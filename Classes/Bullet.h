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

	// 初期化処理
	virtual bool init();

	// Createマクロ
	CREATE_FUNC(Bullet);
};

#endif /* BULLET_H_ */
