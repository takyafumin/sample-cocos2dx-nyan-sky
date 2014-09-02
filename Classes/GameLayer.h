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
		Z_Player = 1,
	};

	// Tag定義
	enum Tag
	{
		Tag_Bg = 1,
		Tag_Player = 2,
	};

	// プレイヤー
	Player* _player;


	// 背景初期化処理
	void initBackground();

	// プレイヤー初期化処理
	void initPlayer();

	// タップイベントの初期化
	void initTouchEvent();


public:
	// CreateScene
	static cocos2d::Scene* createScene();

	// 初期化処理
	virtual bool init();

	// Create
	CREATE_FUNC(GameLayer);

	// タップイベント
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

};

#endif /* GAMELAYER_H_ */
