/*
 * Bullet.h
 *
 *  Created on: 2014/09/03
 *      Author: takyafumin
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "cocos2d.h"

class Bullet: public cocos2d::Sprite {

public:

	// 弾の状態
	enum class State
	{
		Moving,
		Broken,
	};

	// コンストラクタ
	//Bullet();

	// 初期化処理
	virtual bool init();

	// Createマクロ
	CREATE_FUNC(Bullet);

	// 弾の状態
	CC_SYNTHESIZE_READONLY(State, _state, State);

	// 当たり判定の半径
	CC_SYNTHESIZE(float, _radius, Radius);

	// 弾が壊れる処理
	void brokenBullet();
};

#endif /* BULLET_H_ */
