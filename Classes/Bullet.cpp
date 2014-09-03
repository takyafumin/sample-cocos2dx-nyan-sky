/*
 * Bullet.cpp
 *
 *  Created on: 2014/09/03
 *      Author: takyafumin
 */

#include "cocos2d.h"
#include "Bullet.h"

#define PNG_BULLET "Bullet.png"

USING_NS_CC;


bool Bullet::init()
{
	if (!Sprite::initWithFile(PNG_BULLET))
		return false;


	// 画面サイズ取得
	auto winSize = Director::getInstance()->getWinSize();

	// 移動アニメーション生成
	auto move = MoveBy::create(1, Vec2(0, winSize.height));
	auto remove = RemoveSelf::create();
	auto seq = Sequence::create(move, remove, nullptr);

	// 実行
	this->runAction(seq);


	// 当たり判定の半径を設定
	_radius = this->getContentSize().width * 0.5;

	return true;
}


/**
 * 弾が壊れる時の処理
 */
void Bullet::brokenBullet()
{
	this->stopAllActions();

	// 弾を消すアクション
	Action* action = RemoveSelf::create();
	runAction(action);

	// 状態を変更
	_state = State::Broken;
}
