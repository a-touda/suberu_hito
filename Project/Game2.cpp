#include	"GameApp.h"
#include	"Game2.h"
#include	"Player.h"
#include	"GameDefine.h"

/**
 * コンストラクタ
 *
 */
CGame2::CGame2() {
}

/**
 * デストラクタ
 *
 */
CGame2::~CGame2() {
}

/**
*	読み込み
*	利用するテクスチャを読み込む
*/
bool CGame2::Load(void) {

	//プレイヤー素材の読み込み
	m_Player.Load();

	return true;
}

/**
 * 初期化
 * パラメーターや座標を初期化する。
 * 状態を初期化したいときに実行する。
 */
void CGame2::Initialize(void) {
	//プレイヤーの状態初期化
	m_Player.Initialize();

	m_bEnd = false;
}

/**
 * 更新
 *
 */
void CGame2::Update(void) {
	//プレイヤーの更新
	m_Player.Update();

	//ステージとプレイヤーの当たり判定
	float ox = 0, oy = 0;
	/*if (m_Stage.Collision(m_Player.GetRect(), ox, oy))
	{
		m_Player.CollisionStage(ox, oy);
	}*/

	//F1キーでゲームクリア画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAMECLEAR;
	}

	//F2キーでゲームオーバー画面へ
	if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAMEOVER;
	}
}

/**
 * 描画
 *
 */
void CGame2::Render(void) {
	CGraphicsUtilities::RenderString(10, 10, "ゲーム画面(２)");
	CGraphicsUtilities::RenderString(10, 40, "F1とF2キーで画面遷移");

	//プレイヤーの描画
	m_Player.Render();

}

/**
 * デバッグ描画
 *
 */
void CGame2::RenderDebug(void) {
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		//プレイヤーのデバッグ描画
		m_Player.RenderDebug();
	}
}

/**
*	解放
*/
void CGame2::Release(void) {
	//プレイヤーの解放
	m_Player.Release();
}