#include	"Player.h"

/**
 * �R���X�g���N�^
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
 * �f�X�g���N�^
 *
 */
CPlayer::~CPlayer(){
}

/**
 * �ǂݍ���
 * ���p����e�N�X�`����ǂݍ��ށB
 */
bool CPlayer::Load(void){
	//�e�N�X�`���̓ǂݍ���
	if (!m_Texture.Load("Player2.png"))
	{
		return false;
	}

	//�A�j���[�V�����̍쐬
	/*SpriteAnimationCreate anim[] = {
		{
		
		}
	};
	m_Motion.Create(anim, MOTION_COUNT);*/
	return true;
}

/**
 * ������
 * �p�����[�^�[����W������������B
 * �v���C���[�̈ʒu�ȂǏ�Ԃ��������������Ƃ��Ɏ��s����B
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
 * �X�V
 *
 */
void CPlayer::Update(void){
	//�ړ��t���O�A���̃t���[���ł̈ړ�������������ۑ�
	m_bMove = false;
	//���ۂɍ��W���ړ�����
	m_PosX += m_MoveX;
	m_PosY += m_MoveY;
	//�A�j���[�V�����̍X�V
	m_Motion.AddTimer(CUtilities::GetFrameSecond());
	m_SrcRect = m_Motion.GetSrcRect();
}

/**
 * �L�[���͂ɂ�铮��X�V
 *
 */
void CPlayer::UpdateKey(void){
	//�L�[�{�[�h�ł̈ړ�
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
 * �ړ��X�V
 *
 */
void CPlayer::UpdateMove(void){
}

/**
 * �`��
 *
 */
void CPlayer::Render(void){
	//�`���`
	CRectangle dr = m_SrcRect;
	//�`��ʒu
	float px = m_PosX;
	float py = m_PosY;
	//���]�t���O��ON�̏ꍇ�`���`�𔽓]������
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
	//�e�N�X�`���̕`��
	m_Texture.Render(px, py, dr);

}

/**
 * �f�o�b�O�`��
 *
 */
void CPlayer::RenderDebug(void){
	//�ʒu�̕`��
	CGraphicsUtilities::RenderString(10,70,"�v���C���[�ʒu X : %.0f , Y : %.0f",m_PosX,m_PosY);

	//�����蔻��̕\��
	CRectangle hr = GetRect();
	CGraphicsUtilities::RenderRect(hr.Left,hr.Top,hr.Right,hr.Bottom,MOF_XRGB(0,255,0));

	//�U���̓����蔻��\��
	if(IsAttack())
	{
		CRectangle hr = GetAttackRect();
		CGraphicsUtilities::RenderRect(hr.Left,hr.Top,hr.Right,hr.Bottom,MOF_XRGB(255,0,0));
	}
}
/**
 * �X�e�[�W�Ƃ̓����蔻��
 *
 */
void CPlayer::CollisionStage(float ox, float oy) {
	m_PosX += ox;
	m_PosY += oy;
	//���ړ����̍����܂�A�E�ړ����̉E���܂�̏ꍇ�͈ړ�������������B
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
	//�������̉����܂�A��ړ����̏㖄�܂�̏ꍇ�͈ړ�������������B
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
 * ���
 *
 */
void CPlayer::Release(void){
	m_Texture.Release();
	m_Motion.Release();
}
