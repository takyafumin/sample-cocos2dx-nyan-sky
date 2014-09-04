/*
 * Player.cpp
 *
 *  Created on: 2014/09/02
 *      Author: takyafumin
 */

#include "Player.h"

// プレイヤー画像
#define PNG_PLAYER "Player.png"
// 爆発画像
#define PNG_EXPLOTION1 "Explosion1.png"
#define PNG_EXPLOTION2 "Explosion2.png"

// 無敵インターバル
#define NO_COLLI


USING_NS_CC;


/**
 * 初期化処理
 *
 * @return 実行結果
 */
bool Player::init()
{
	if (!Sprite::initWithFile(PNG_PLAYER))
		return false;

	// HP設定
	_hp = 3;

	// 当たり判定の半径を設定
	_radius = getContentSize().width * 0.5;

//	// 敵と当たった時間を設定
//	_hitTime = 0.0;

	// 状態
	_state = Player::State::Normal;

	return true;
}


/**
 * 敵がヒットした時の処理
 *
 * @return true：生存、false：死亡
 */
bool Player::hitPlayer()
{
	bool isLive = true;

	// ヒットポイントを減らす
	_hp--;

	Action* action;

	if (_hp <= 0)
	{
		isLive = false;
		this->stopAllActions();

		// 状態変更
		_state = Player::State::Dead;

		// 爆発アニメーション生成
		auto explotionBase = Animation::create();
		explotionBase->addSpriteFrameWithFile(PNG_EXPLOTION1);
		explotionBase->addSpriteFrameWithFile(PNG_EXPLOTION2);
		explotionBase->setLoops(3);
		explotionBase->setDelayPerUnit(0.2);

		auto blink = Blink::create(0.2, 2);
		auto explotion = Animate::create(explotionBase);
		auto remove = RemoveSelf::create();

		action = Sequence::create(blink, explotion, nullptr);
	}
	else
	{
		// 状態変更
		_state = Player::State::Damage;

		// 点滅
		auto blink = Blink::create(0.5, 5);
		auto callBackFunc = CallFunc::create(CC_CALLBACK_0(Player::setStateNormal, this));

		action = Sequence::create(blink, callBackFunc, nullptr);
	}


	// アクション実行
	this->runAction(action);

	return isLive;
}


/**
 * 状態変更：Normal
 */
void Player::setStateNormal()
{
	_state = Player::State::Normal;
}
