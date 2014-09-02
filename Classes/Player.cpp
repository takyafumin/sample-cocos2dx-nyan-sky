/*
 * Player.cpp
 *
 *  Created on: 2014/09/02
 *      Author: takyafumin
 */

#include "Player.h"

// プレイヤー画像
#define PNG_PLAYER "Player.png"

USING_NS_CC;


bool Player::init()
{
	if (!Sprite::initWithFile(PNG_PLAYER))
		return false;

	return true;
}

