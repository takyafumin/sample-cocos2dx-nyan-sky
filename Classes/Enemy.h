/*
 * Enemy.h
 *
 *  Created on: 2014/09/03
 *      Author: takyafumin
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include "cocos2d.h"

class Enemy: public cocos2d::Sprite {

public:

	// タイプ
	enum EnemyType
	{
		Type1 = 1,
		Type2 = 2,
	};

protected:

	// タイプ
	EnemyType _enemyType;

	// アクション：Type1
	cocos2d::Action* getAction1();

	// アクション：Type2
cocos2d::Action* getAction2();

public:

	// コンストラクタ
	Enemy(EnemyType enemyType);

	// 初期化処理
	virtual bool init();

	// create関数
	static Enemy* create(EnemyType enemyType);
};

#endif /* ENEMY_H_ */
