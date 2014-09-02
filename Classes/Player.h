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
	// 初期化処理
	virtual bool init();

	// Createマクロ
	CREATE_FUNC(Player);
};

#endif /* PLAYER_H_ */
