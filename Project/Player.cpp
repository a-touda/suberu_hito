#include	"Player.h"

/**
 * コンストラクタ
 *
 */
CPlayer::CPlayer() :
m_Texture() ,
m_Motion() ,
m_PosX(0.0f) ,
m_PosY(0.0f) ,
m_bMove(false) ,
m_MoveX(0.0f) ,
m_MoveY(0.0f) ,
m_bJump(false) ,
m_bReverse(false) ,
m_SrcRect() {
}

/**
 * デストラクタ
 *
 */
CPlayer::~CPlayer(){
}

/**
 * 読み込み
 * 利用するテクスチャを読み込む。
 */
bool CPlayer::Load(void){
	//テクスチャの読み込み
	if (!m_Texture.Load("Player2.png"))
	{
		return false;
	}

	//アニメーションの作成
	/*SpriteAnimationCreate anim[] = {
		{
		
		}
	};
	m_Motion.Create(anim, MOTION_COUNT);*/
	return true;
}

/**
 * 初期化
 * パラメーターや座標を初期化する。
 * プレイヤーの位置など状態を初期化したいときに実行する。
 */
void CPlayer::Initialize(void){
	m_PosX = 0;
	m_PosY = 0;
	m_bMove = false;
	m_MoveX = 0.0f;
	m_MoveY = 0.0f;
	m_bReverse = false;
	m_bJump = false;
	m_Motion.ChangeMotion(MOTION_WAIT);
}

/**
 * 更新
 *
 */
void CPlayer::Update(void){
	//移動フラグ、このフレームでの移動があったかを保存
	m_bMove = false;
	//実際に座標を移動する
	m_PosX += m_MoveX;
	m_PosY += m_MoveY;
	//アニメーションの更新
	m_Motion.AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion.GetSrcRect();
}

/**
 * キー入力による動作更新
 *
 */
void CPlayer::UpdateKey(void){
	//キーボードでの移動
	if(m_bMove = false){
		
		if (g_pInput->IsKeyHold(MOFKEY_LEFT))
		{
			m_MoveX = -PLAYER_SPEED;
			m_bReverse = true;
			m_bMove = true;

		}
		else if (g_pInput->IsKeyHold(MOFKEY_RIGHT))
		{
			m_MoveX = PLAYER_SPEED;
			m_bReverse = false;
			m_bMove = true;

		}
		if (g_pInput->IsKeyHold(MOFKEY_UP))
		{
			m_MoveY = -PLAYER_SPEED;
			m_bMove = true;

		}
		else if (g_pInput->IsKeyHold(MOFKEY_DOWN))
		{
			m_MoveY = PLAYER_SPEED;
			m_bMove = true;

		}
	}
}


/**
 * 移動更新
 *
 */
void CPlayer::UpdateMove(void){
}

/**
 * 描画
 *
 */
void CPlayer::Render(void){
	//描画矩形
	CRectangle dr = m_SrcRect;
	//描画位置
	float px = m_PosX;
	float py = m_PosY;
	//反転フラグがONの場合描画矩形を反転させる
	if (m_bReverse)
	{
		float tmp = dr.Right;
		dr.Right = dr.Left;
		dr.Left = tmp;
		if (m_Motion.GetMotionNo() == MOTION_ATTACK)
		{
			px -= PLAYER_ATTACKWIDTH;
		}
	}
	//テクスチャの描画
	m_Texture.Render(px, py, dr);

}

/**
 * デバッグ描画
 *
 */
void CPlayer::RenderDebug(void){
	//位置の描画
	CGraphicsUtilities::RenderString(10,70,"プレイヤー位置 X : %.0f , Y : %.0f",m_PosX,m_PosY);

	//当たり判定の表示
	CRectangle hr = GetRect();
	CGraphicsUtilities::RenderRect(hr.Left,hr.Top,hr.Right,hr.Bottom,MOF_XRGB(0,255,0));

	//攻撃の当たり判定表示
	if(IsAttack())
	{
		CRectangle hr = GetAttackRect();
		CGraphicsUtilities::RenderRect(hr.Left,hr.Top,hr.Right,hr.Bottom,MOF_XRGB(255,0,0));
	}
}
/**
 * ステージとの当たり判定
 *
 */
void CPlayer::CollisionStage(float ox, float oy) {
	m_PosX += ox;
	m_PosY += oy;
	//左移動中の左埋まり、右移動中の右埋まりの場合は移動を初期化する。
	if (ox < 0 && m_MoveX > 0)
	{
		m_MoveX = 0;
		m_bMove = false;
	}
	else if (ox > 0 && m_MoveX < 0)
	{
		m_MoveX = 0;
		m_bMove = false;
	}
	//落下中の下埋まり、上移動中の上埋まりの場合は移動を初期化する。
	if (oy < 0 && m_MoveY > 0)
	{
		m_MoveY = 0;
		m_bMove = false;
		
	}
	else if (oy > 0 && m_MoveY < 0)
	{
		m_MoveY = 0;
		m_bMove = false;
	}
}

/**
 * 解放
 *
 */
void CPlayer::Release(void){
	m_Texture.Release();
	m_Motion.Release();
}
