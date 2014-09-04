/*
 * Player.h
 *
 *  Created on: 2014/09/02
 *      Author: takyafumin
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "cocos2d.h"

class Player: public cocos2d::Sprite {

public:

	// 状態
	enum class State
	{
		Normal,
		Damage,
		Dead,
	};

protected:

	// HP
	int _hp;

	// 状態変更：Normal
	void setStateNormal();

public:
	// 初期化処理
	virtual bool init();

	// Createマクロ
	CREATE_FUNC(Player);

	// 敵がヒットした場合の処理
	bool hitPlayer();

	//
	// アクセサ
	//

	// 当たり判定の半径
	CC_SYNTHESIZE_READONLY(float, _radius, Radius);

	// 自機の状態
	CC_SYNTHESIZE_READONLY(State, _state, State);
};

#endif /* PLAYER_H_ */
