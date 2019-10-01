#include	"Enemy.h"

/**
 * �R���X�g���N�^
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
 * �f�X�g���N�^
 *
 */
CEnemy::~CEnemy() {
	//delete[] �ŉ�������悤��Release���f�X�g���N�^�Ŏ��s����
	Release();
}

/**
 * ������
 * �p�����[�^�[����W������������B
 *
 * ����
 * [in]			px					X���W
 * [in]			py					Y���W
 * [in]			type				�G�^�C�v
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

	//���A�j���[�V�������쐬
}

/**
 * �X�V
 *
 */
void CEnemy::Update(void) {
	//��\��
	if (!m_bShow)
	{
		return;
	}

	//���ۂɍ��W���ړ�������
	m_PosX += m_MoveX;
	m_PosY += m_MoveY;

}

/**
 * �X�e�[�W�Ƃ̓�����
 *
 * ����
 * [in]			ox					X���܂��
 * [in]			oy					Y���܂��
 */
void CEnemy::CollisionStage(float ox, float oy) {
	m_PosX += ox;
	m_PosY += oy;
	//��ړ����̏㖄�܂�A���ړ����̉����܂�̏ꍇ�͈ړ�������������B
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
	//���ړ����̍����܂�A�E�ړ����̉E���܂�̏ꍇ�͈ړ�������������B
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
* �_���[�W����
* �U���̎�ނɉ����ď���������~�܂����肷��
*
* ����
* [in]		dmg			�_���[�W
* [in]		bRev		���]�t���O
*/
void CEnemy::Damage(int dmg, bool bRev) {

}

/**
 * �`��
 *
 * ����
 * [in]			wx					���[���h�̕ω�
 * [in]			wy					���[���h�̕ω�
 */
void CEnemy::Render(float wx, float wy) {
	//��\��
	if (!m_bShow)
	{
		return;
	}

	//�`���`
	CRectangle dr = m_SrcRect;
	//���]�t���O��ON�̏ꍇ�`���`�𔽓]������(��)
	if (m_bWReverse)
	{
		float tmp = dr.Right;
		dr.Right = dr.Left;
		dr.Left = tmp;
	}
	//���]�t���O��ON/OFF�ŕ`�悷��摜��ύX����(�c)
	if (m_bHReverse)
	{

	}
	else
	{

	}

	//�e�N�X�`���̕`��
	m_pTexture->Render(m_PosX - wx, m_PosY - wy, dr);

}

/**
 * �f�o�b�O�`��
 *
 * ����
 * [in]			wx					���[���h�̕ω�
 * [in]			wy					���[���h�̕ω�
 */
void CEnemy::RenderDebug(float wx, float wy) {
	//��\��
	if (!m_bShow)
	{
		return;
	}
	//�����蔻��̕\��
	CRectangle hr = GetRect();
	CGraphicsUtilities::RenderRect(hr.Left - wx, hr.Top - wy, hr.Right - wx, hr.Bottom - wy, MOF_XRGB(255, 0, 0));

}

/**
 * ���
 *
 */
void CEnemy::Release(void) {
	m_Motion.Release();
}

//�A�j���[�V�����ƃ_���[�W�̃R�[�h�܂������ĂȂ�