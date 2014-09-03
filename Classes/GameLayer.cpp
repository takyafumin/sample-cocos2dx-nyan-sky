/*
 * GameLayer.cpp
 *
 *  Created on: 2014/09/02
 *      Author: takyafumin
 */

#include "cocos2d.h"
#include "GameLayer.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"


// 背景画像
#define PNG_BACKGROUND "Background.png"

// 弾の発射感覚
#define BULLET_INTERVAL 0.5f


USING_NS_CC;


/**
 * シーン生成
 *
 * @return シーン
 */
Scene* GameLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = GameLayer::create();
	scene->addChild(layer);

	return scene;
}


/**
 * 初期化処理
 */
bool GameLayer::init()
{
	if (!Layer::init())
		return false;

	// 背景初期化
	initBackground();

	// プレイヤーを表示
	initPlayer();

	// タップイベントの初期化
	initTouchEvent();

	// 敵設定の初期化
	initEnemyConfigs();

	// フレーム処理を設定
	scheduleUpdate();

	return true;
}


/**
 * 背景初期化処理
 */
void GameLayer::initBackground()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// 背景スプライト生成
	auto background = Sprite::create(PNG_BACKGROUND);

	// 背景アンカーポイント設定
	background->setAnchorPoint(Vec2(0.5, 0));

	// 背景の位置設定
	background->setPosition(Vec2(winSize.width / 2, 0));

	// 背景を追加
	this->addChild(background, Z_Bg, Tag_Bg);


	// アニメーション生成
	auto destPosition = Vec2(winSize.width / 2, winSize.height - background->getContentSize().height);
	auto move = MoveTo::create(120, destPosition);

	// アクション実行
	background->runAction(move);
}

/**
 * プレイヤー初期化処理
 */
void GameLayer::initPlayer()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// プレイヤーの生成
	_player = Player::create();

	// 位置設定
	_player->setPosition(winSize.width * 0.5, winSize.height * 0.2);

	// 画面へ追加
	this->addChild(_player, Z_Player, Tag_Player);
}


/**
 * タップイベント初期化処理
 */
void GameLayer::initTouchEvent()
{

	// シングルタップイベントの取得設定
	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GameLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(GameLayer::onTouchEnded, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(GameLayer::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}




#define mark - タップイベント

bool GameLayer::onTouchBegan(Touch* touch, Event* event)
{
	return true;
}

void GameLayer::onTouchMoved(Touch* touch, Event* event)
{
	// スワイプした移動距離分、プレイヤーを移動する
	_player->setPosition(_player->getPosition() + touch->getDelta());
}

void GameLayer::onTouchEnded(Touch* touch, Event* event)
{
}

void GameLayer::onTouchCancelled(Touch* touch, Event* event)
{
	onTouchEnded(touch, event);
}

/**
 * 敵の初期化処理
 */
void GameLayer::initEnemyConfigs()
{
	_enemyConfigs =
	{
			{1, 2},
			{1, 3},
			{1, 4},
			{1, 5},
			{1, 6},

			{2, 8},
			{2, 9},
			{2, 10},
			{2, 11},
			{2, 12},
	};
}


/**
 * フレーム処理
 */
void GameLayer::update(float dt)
{
	// トータル時間を加算
	_time += dt;

	// 敵の表示設定
	if (_enemyConfigs.size() != 0 && _enemyConfigs[0].appearanceTime <= _time)
	{
		// まだ出現していない敵が存在する
		showEnemy();
	}

	// 弾の表示
	if (_lastBulletTime + BULLET_INTERVAL < _time)
	{
		showBullet();
	}


	// 当たり判定
	collisionDetection();
}


/**
 * 敵の表示処理
 */
void GameLayer::showEnemy()
{
	// 敵を生成
	auto type = static_cast<Enemy::EnemyType>(_enemyConfigs[0].enemyType);
	auto enemy = Enemy::create(type);

	// シーンへ追加
	this->addChild(enemy, Z_Enemy, Tag_Enemy);


	// 配列から設定済みの敵を削除
	_enemyConfigs.erase(_enemyConfigs.begin());
}


/**
 * 弾の表示処理
 */
void GameLayer::showBullet()
{
	// 弾を生成
	auto bullet = Bullet::create();
	bullet->setPosition(_player->getPosition());

	this->addChild(bullet, Z_Bullet, Tag_Bullet);

	// 弾の発射時間を保持
	_lastBulletTime = _time;
}


void GameLayer::collisionDetection()
{
	// ノードリスト取得
	auto nodes = getChildren();
	Vector<Node*> enemies;
	Vector<Node*> bullets;

	for (auto node : nodes)
	{
		switch (node->getTag())
		{
		case Tag_Bullet: bullets.pushBack(node); break;
		case Tag_Enemy: enemies.pushBack(node); break;
		default: break;
		}
	}


	// 敵の数分ループ
	for (auto nodeEnemy : enemies)
	{
		auto enemy = static_cast<Enemy*>(nodeEnemy);
		if (enemy->getState() == Enemy::State::Dead)
			continue;

		// 弾の数分ループ
		for (auto nodeBullet : bullets)
		{
			auto bullet = static_cast<Bullet*>(nodeBullet);
			if (bullet->getState() == Bullet::State::Broken)
				continue;

			// 敵と弾の距離を取得
			float distance = enemy->getPosition().distance(bullet->getPosition());

			if (distance <= enemy->getRadius() + bullet->getRadius())
			{
				enemy->hitEnemy();
				bullet->brokenBullet();
			}
		}
	}
}
