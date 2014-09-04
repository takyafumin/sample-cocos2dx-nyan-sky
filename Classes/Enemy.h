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
		Type3 = 3,
		Type4 = 4,
		Type5 = 5,
	};

	// 状態
	enum class State
	{
		Moving,
		Dead,
	};

protected:

	// タイプ
	EnemyType _enemyType;

	// HP
	int _hp;

	// TODO
//	// アクション：Type1
//	cocos2d::Action* getAction1();
//
//	// アクション：Type2
//	cocos2d::Action* getAction2();

	// アクション：標準（まっすぐ）
	cocos2d::Action* getActionNormal(float destX);

public:

	// コンストラクタ
	Enemy(EnemyType enemyType);

	// 初期化処理
	virtual bool init();

	// create関数
	static Enemy* create(EnemyType enemyType);


	//
	// アクセサ
	//

	// 敵の状態
	CC_SYNTHESIZE_READONLY(State, _state, State);
	// 当たり判定の半径
	CC_SYNTHESIZE(float, _radius, Radius);

	// 弾がヒットした場合の処理
	void hitEnemy();

};

#endif /* ENEMY_H_ */
