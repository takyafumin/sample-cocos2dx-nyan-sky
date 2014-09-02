/*
 * GameLayer.cpp
 *
 *  Created on: 2014/09/02
 *      Author: takyafumin
 */

#include "cocos2d.h"
#include "GameLayer.h"

// 背景画像
#define PNG_BACKGROUND "Background.png"


USING_NS_CC;


/**
 * シーン生成
 *
 * @return シーン
 */
Scene* GameLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = GameLayer::create();
	scene->addChild(layer);

	return scene;
}


/**
 * 初期化処理
 */
bool GameLayer::init()
{
	if (!Layer::init())
		return false;

	// 背景初期化
	initBackground();

	return true;
}


/**
 * 背景初期化処理
 */
void GameLayer::initBackground()
{
	// 画面サイズ取得
	Size winSize = Director::getInstance()->getWinSize();

	// 背景スプライト生成
	auto background = Sprite::create(PNG_BACKGROUND);

	// 背景アンカーポイント設定
	background->setAnchorPoint(Vec2(0.5, 0));

	// 背景の位置設定
	background->setPosition(Vec2(winSize.width / 2, 0));

	// 背景を追加
	this->addChild(background, Z_Bg, Tag_Bg);


	// アニメーション生成
	auto destPosition = Vec2(winSize.width / 2, winSize.height - background->getContentSize().height);
	auto move = MoveTo::create(120, destPosition);

	background->runAction(move);

	return;
}
