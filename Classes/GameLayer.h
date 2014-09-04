/*
 * GameLayer.h
 *
 *  Created on: 2014/09/02
 *      Author: takyafumin
 */

#ifndef GAMELAYER_H_
#define GAMELAYER_H_

#include "cocos2d.h"
#include "Player.h"


class GameLayer: public cocos2d::Layer {
protected:

	// ZOrder定義
	enum ZOrder
	{
		Z_Bg = 0,
		Z_Bullet,
		Z_Enemy,
		Z_Player,
	};

	// Tag定義
	enum Tag
	{
		Tag_Bg = 1,
		Tag_Player = 2,
		Tag_Enemy = 3,
		Tag_Bullet = 4,
	};

	// 敵の設定
	struct EnemyConfig
	{
		int enemyType;
		float appearanceTime;
	};

	// プレイヤー
	Player* _player;

	// ゲーム時間
	float _time;

	// 敵の設定
	std::vector<EnemyConfig> _enemyConfigs;

	// 弾を発射した時間
	float _lastBulletTime;

	// 弾の発射間隔設定
	std::vector<float> _bulletIntervalConfigs;
	int _bulletIntervalConfigsIndex;


	// 背景初期化処理
	void initBackground();

	// プレイヤー初期化処理
	void initPlayer();

	// タップイベントの初期化
	void initTouchEvent();

	// 敵設定の初期化
	void initEnemyConfigs();

	// 弾発射間隔設定の初期化
	void initBulletIntervalConfigs();

	// 敵の表示
	void showEnemy();

	// 弾の表示
	void showBullet();

	// 当たり判定処理
	void collisionDetection();

public:
	// CreateScene
	static cocos2d::Scene* createScene();

	// 初期化処理
	virtual bool init();

	// Createマクロ
	CREATE_FUNC(GameLayer);

	// フレーム処理
	virtual void update(float dt);

	// タップイベント
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

};

#endif /* GAMELAYER_H_ */
