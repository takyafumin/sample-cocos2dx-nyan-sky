/*
 * Enemy.cpp
 *
 *  Created on: 2014/09/03
 *      Author: takyafumin
 */

#include "cocos2d.h"
#include "Enemy.h"

#define PNG_ENEMY1 "Enemy1.png"
#define PNG_ENEMY2 "Enemy2.png"

USING_NS_CC;

Enemy::Enemy(EnemyType enemyType)
: _enemyType(enemyType)
, _hp(0)
, _state(Enemy::State::Moving)
, _radius(0.0)
{
}


Enemy* Enemy::create(EnemyType enemyType)
{
	auto enemy = new Enemy(enemyType);
	enemy->init();
	enemy->autorelease();

	return enemy;
}


/**
 * 初期化処理
 */
bool Enemy::init()
{
	// 画面サイズ取得
	auto winSize = Director::getInstance()->getWinSize();

	std::string filename;
	Vec2 initPos;
	Action* action;

	switch (_enemyType)
	{
	case Type1:
		_hp = 2;
		filename = PNG_ENEMY1;
		initPos = Vec2(winSize.width * 0.1, winSize.height * 1.1);
		action = getActionNormal(0.1);
		break;

	case Type2:
		_hp = 2;
		filename = PNG_ENEMY1;
		initPos = Vec2(winSize.width * 0.3, winSize.height * 1.1);
		action = getActionNormal(0.3);
		break;

	case Type3:
		_hp = 2;
		filename = PNG_ENEMY1;
		initPos = Vec2(winSize.width * 0.5, winSize.height * 1.1);
		action = getActionNormal(0.5);
		break;

	case Type4:
		_hp = 2;
		filename = PNG_ENEMY1;
		initPos = Vec2(winSize.width * 0.7, winSize.height * 1.1);
		action = getActionNormal(0.7);
		break;

	case Type5:
		_hp = 2;
		filename = PNG_ENEMY1;
		initPos = Vec2(winSize.width * 0.9, winSize.height * 1.1);
		action = getActionNormal(0.9);
		break;
	}

	if (!Sprite::initWithFile(filename))
		return false;


	// 初期位置とアクションを設定
	setPosition(initPos);
	runAction(action);

	// 当たり判定の半径を設定
	_radius = getContentSize().width * 0.5;

	return true;
}


/**
 * アクション取得
 *     - まっすぐ降りてくる
 *
 * @param dextX 移動先X座標
 * @return アクションインスタンス
 */
Action* Enemy::getActionNormal(float destX)
{
	// 画面サイズ取得
	auto winSize = Director::getInstance()->getWinSize();

	// 移動アクション生成
	auto move = MoveTo::create(5, Vec2(winSize.width * destX, winSize.height * -0.1));
	auto remove = RemoveSelf::create();
	auto seq = Sequence::create(move, remove, nullptr);

	return seq;
}


/**
 * 弾がヒットした時の処理
 */
void Enemy::hitEnemy()
{
	// ヒットポイントを減らす
	_hp--;

	Action* action;

	if (_hp <= 0)
	{
		// アニメーションストップ
		this->stopAllActions();

		// 爆発
		action = RemoveSelf::create();
		_state = State::Dead;
	}
	else
	{
		// 点滅
		action = Blink::create(0.2, 2);
	}

	runAction(action);
}
