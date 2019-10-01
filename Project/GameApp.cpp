/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"

#include	"GameDefine.h"
#include	"Title.h"
#include	"Gameselect.h"
#include	"Game.h"
#include	"Game2.h"
#include	"Game3.h"
#include	"GameClear.h"
#include	"GameOver.h"


//現在のシーン
int						gScene = SCENENO_TITLE;

//変更するシーン
int						gChangeScene = SCENENO_TITLE;

//各シーンクラス
CTitle					gTitleScene;
CGame					gGameScene;
CGame2					gGame_2Scene;
CGame3					gGame_3Scene;
CGameselect             gGameselectScene;
CGameClear				gGameClearScene;
CGameOver				gGameOverScene;



/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void){
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectory("Resource");

	//タイトル画面の素材の読み込み
	gTitleScene.Load();

	//ゲーム選択画面の素材の読み込み
	gGameselectScene.Load();

	//ゲーム画面の素材の読み込み
	gGameScene.Load();
	gGame_2Scene.Load();
	gGame_3Scene.Load();
	gGameClearScene.Load();
	gGameOverScene.Load();

	//最初に実行されるシーンの初期化
	gTitleScene.Initialize();

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの更新
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Update(void){
	//キーの更新
	g_pInput->RefreshKey();

	//シーン番号によって更新
	switch (gScene)
	{
	case SCENENO_TITLE:			gTitleScene.Update();			break;
	case SCENENO_GAME:			gGameScene.Update();			break;
	case SCENENO_GAME2:			gGame_2Scene.Update();			break;
	case SCENENO_GAME3:			gGame_3Scene.Update();			break;
	case SCENENO_GAMESELECT:	gGameselectScene.Update();		break;
	case SCENENO_GAMECLEAR:		gGameClearScene.Update();		break;
	case SCENENO_GAMEOVER:		gGameOverScene.Update();		break;
	}


	//シーンが終了している場合、次のシーン番号を更新
	switch (gScene)
	{
	case SCENENO_TITLE:			
		if (gTitleScene.IsEnd()) { gChangeScene = gTitleScene.GetNextScene(); }					break;
	case SCENENO_GAME:			
		if (gGameScene.IsEnd()) { gChangeScene = gGameScene.GetNextScene(); }					break;
	case SCENENO_GAME2:			
		if (gGame_2Scene.IsEnd()) { gChangeScene = gGame_2Scene.GetNextScene(); }				break;
	case SCENENO_GAME3:			
		if (gGame_3Scene.IsEnd()) { gChangeScene = gGame_3Scene.GetNextScene(); }				break;
	case SCENENO_GAMESELECT:	
		if (gGameselectScene.IsEnd()) { gChangeScene = gGameselectScene.GetNextScene(); }		break;
	case SCENENO_GAMECLEAR:
		if (gGameClearScene.IsEnd()) { gChangeScene = gGameClearScene.GetNextScene(); }			break;
	case SCENENO_GAMEOVER:
		if (gGameOverScene.IsEnd()) { gChangeScene = gGameOverScene.GetNextScene(); }			break;
	}


	//シーン変更があった場合変更先シーンの初期化
	if (gChangeScene != gScene)
	{
		switch (gChangeScene)
		{
		case SCENENO_TITLE:			gTitleScene.Initialize();			break;
		case SCENENO_GAME:			gGameScene.Initialize();			break;
		case SCENENO_GAME2:			gGame_2Scene.Initialize();			break;
		case SCENENO_GAME3:			gGame_3Scene.Initialize();			break;
		case SCENENO_GAMESELECT:	gGameselectScene.Initialize();		break;
		case SCENENO_GAMECLEAR:		gGameClearScene.Initialize();		break;
		case SCENENO_GAMEOVER:		gGameOverScene.Initialize();		break;
		}
		gScene = gChangeScene;
	}

	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの描画
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//描画開始
	g_pGraphics->RenderStart();
	//画面のクリア
	g_pGraphics->ClearTarget(0.0f,0.0f,1.0f,0.0f,1.0f,0);

	//シーン番号によって描画
	switch (gScene)
	{
	case SCENENO_TITLE:			gTitleScene.Render();		break;
	case SCENENO_GAME:			gGameScene.Render();		break;
	case SCENENO_GAME2:			gGame_2Scene.Render();		break;
	case SCENENO_GAME3:			gGame_3Scene.Render();		break;
	case SCENENO_GAMESELECT:	gGameselectScene.Render();	break;
	case SCENENO_GAMECLEAR:		gGameClearScene.Render();	break;
	case SCENENO_GAMEOVER:		gGameOverScene.Render();    break;
	}

	//描画の終了
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの解放
		@param			None
				
		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Release(void){
	//タイトル画面の解放
	gTitleScene.Release();

	//ゲーム画面の解放
	gGameScene.Release();
	gGame_2Scene.Release();
	gGame_3Scene.Release();

	//ゲーム選択画面の解放
	gGameselectScene.Release();

	//ゲームクリア・オーバー画面の解放
	gGameClearScene.Release();
	gGameOverScene.Release();

	return TRUE;
}