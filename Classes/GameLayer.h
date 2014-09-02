/*
 * GameLayer.h
 *
 *  Created on: 2014/09/02
 *      Author: takyafumin
 */

#ifndef GAMELAYER_H_
#define GAMELAYER_H_

#include "cocos2d.h"


class GameLayer: public cocos2d::Layer {
protected:

	// ZOrder定義
	enum ZOrder
	{
		Z_Bg = 0,
	};

	// Tag定義
	enum Tag
	{
		Tag_Bg = 1,
	};

	// 背景初期化処理
	void initBackground();


public:
	// CreateScene
	static cocos2d::Scene* createScene();

	// 初期化処理
	virtual bool init();

	// Create
	CREATE_FUNC(GameLayer);
};

#endif /* GAMELAYER_H_ */
