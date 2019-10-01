#include	"Enemy.h"

/**
 * コンストラクタ
 *
 */
CEnemy::CEnemy() :
	m_pTexture(NULL),
	m_Motion(),
	m_PosX(0.0f),
	m_PosY(0.0f),
	m_MoveX(0.0f),
	m_MoveY(0.0f),
	m_bShow(false),
	m_bWReverse(false),
	m_bHReverse(false),
	m_SrcRect() {
}

/**
 * デストラクタ
 *
 */
CEnemy::~CEnemy() {
	//delete[] で解放されるようにReleaseをデストラクタで実行する
	Release();
}

/**
 * 初期化
 * パラメーターや座標を初期化する。
 *
 * 引数
 * [in]			px					X座標
 * [in]			py					Y座標
 * [in]			type				敵タイプ
 */
void CEnemy::Initialize(float px, float py, int type) {
	m_Type = type;
	m_PosX = px;
	m_PosY = py;
	m_MoveX = -3.0f;
	m_MoveY = 0.0f;
	m_bWReverse = true;
	m_bHReverse = true;
	m_bShow = true;
	m_HP = 10;
	m_DamageWait = 0;

	//↓アニメーションを作成
}

/**
 * 更新
 *
 */
void CEnemy::Update(void) {
	//非表示
	if (!m_bShow)
	{
		return;
	}

	//実際に座標を移動させる
	m_PosX += m_MoveX;
	m_PosY += m_MoveY;

}

/**
 * ステージとの当たり
 *
 * 引数
 * [in]			ox					X埋まり量
 * [in]			oy					Y埋まり量
 */
void CEnemy::CollisionStage(float ox, float oy) {
	m_PosX += ox;
	m_PosY += oy;
	//上移動中の上埋まり、下移動中の下埋まりの場合は移動を初期化する。
	if (oy < 0 && m_MoveY > 0)
	{
		m_MoveY *= -1;
		m_bHReverse = true;
	}
	else if (oy > 0 && m_MoveY < 0)
	{
		m_MoveY *= -1;
		m_bHReverse = false;
	}
	//左移動中の左埋まり、右移動中の右埋まりの場合は移動を初期化する。
	if (ox < 0 && m_MoveX > 0)
	{
		m_MoveX *= -1;
		m_bWReverse = true;
	}
	else if (ox > 0 && m_MoveX < 0)
	{
		m_MoveX *= -1;
		m_bWReverse = false;
	}
}

/**
* ダメージ処理
* 攻撃の種類に応じて消去したり止まったりする
*
* 引数
* [in]		dmg			ダメージ
* [in]		bRev		反転フラグ
*/
void CEnemy::Damage(int dmg, bool bRev) {

}

/**
 * 描画
 *
 * 引数
 * [in]			wx					ワールドの変化
 * [in]			wy					ワールドの変化
 */
void CEnemy::Render(float wx, float wy) {
	//非表示
	if (!m_bShow)
	{
		return;
	}

	//描画矩形
	CRectangle dr = m_SrcRect;
	//反転フラグがONの場合描画矩形を反転させる(横)
	if (m_bWReverse)
	{
		float tmp = dr.Right;
		dr.Right = dr.Left;
		dr.Left = tmp;
	}
	//反転フラグがON/OFFで描画する画像を変更する(縦)
	if (m_bHReverse)
	{

	}
	else
	{

	}

	//テクスチャの描画
	m_pTexture->Render(m_PosX - wx, m_PosY - wy, dr);

}

/**
 * デバッグ描画
 *
 * 引数
 * [in]			wx					ワールドの変化
 * [in]			wy					ワールドの変化
 */
void CEnemy::RenderDebug(float wx, float wy) {
	//非表示
	if (!m_bShow)
	{
		return;
	}
	//当たり判定の表示
	CRectangle hr = GetRect();
	CGraphicsUtilities::RenderRect(hr.Left - wx, hr.Top - wy, hr.Right - wx, hr.Bottom - wy, MOF_XRGB(255, 0, 0));

}

/**
 * 解放
 *
 */
void CEnemy::Release(void) {
	m_Motion.Release();
}

//アニメーションとダメージのコードまだ書いてない