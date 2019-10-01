#include	"GameApp.h"
#include	"Game3.h"
#include	"Player.h"
#include	"GameDefine.h"

/**
 * コンストラクタ
 *
 */
CGame3::CGame3() {
}

/**
 * デストラクタ
 *
 */
CGame3::~CGame3() {
}

/**
*	読み込み
*	利用するテクスチャを読み込む
*/
bool CGame3::Load(void) {

	//プレイヤー素材の読み込み
	m_Player.Load();

	return true;
}

/**
 * 初期化
 * パラメーターや座標を初期化する。
 * 状態を初期化したいときに実行する。
 */
void CGame3::Initialize(void) {
	//プレイヤーの状態初期化
	m_Player.Initialize();

	m_bEnd = false;
}

/**
 * 更新
 *
 */
void CGame3::Update(void) {
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
void CGame3::Render(void) {
	CGraphicsUtilities::RenderString(10, 10, "ゲーム画面(３)");
	CGraphicsUtilities::RenderString(10, 40, "F1とF2キーで画面遷移");

	//プレイヤーの描画
	m_Player.Render();

}

/**
 * デバッグ描画
 *
 */
void CGame3::RenderDebug(void) {
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		//プレイヤーのデバッグ描画
		m_Player.RenderDebug();
	}
}

/**
*	解放
*/
void CGame3::Release(void) {
	//プレイヤーの解放
	m_Player.Release();
}