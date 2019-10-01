#include	"GameApp.h"
#include	"Game3.h"
#include	"Player.h"
#include	"GameDefine.h"

/**
 * �R���X�g���N�^
 *
 */
CGame3::CGame3() {
}

/**
 * �f�X�g���N�^
 *
 */
CGame3::~CGame3() {
}

/**
*	�ǂݍ���
*	���p����e�N�X�`����ǂݍ���
*/
bool CGame3::Load(void) {

	//�v���C���[�f�ނ̓ǂݍ���
	m_Player.Load();

	return true;
}

/**
 * ������
 * �p�����[�^�[����W������������B
 * ��Ԃ��������������Ƃ��Ɏ��s����B
 */
void CGame3::Initialize(void) {
	//�v���C���[�̏�ԏ�����
	m_Player.Initialize();

	m_bEnd = false;
}

/**
 * �X�V
 *
 */
void CGame3::Update(void) {
	//�v���C���[�̍X�V
	m_Player.Update();

	//�X�e�[�W�ƃv���C���[�̓����蔻��
	float ox = 0, oy = 0;
	/*if (m_Stage.Collision(m_Player.GetRect(), ox, oy))
	{
		m_Player.CollisionStage(ox, oy);
	}*/

	//F1�L�[�ŃQ�[���N���A��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAMECLEAR;
	}

	//F2�L�[�ŃQ�[���I�[�o�[��ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_F2))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAMEOVER;
	}
}

/**
 * �`��
 *
 */
void CGame3::Render(void) {
	CGraphicsUtilities::RenderString(10, 10, "�Q�[�����(�R)");
	CGraphicsUtilities::RenderString(10, 40, "F1��F2�L�[�ŉ�ʑJ��");

	//�v���C���[�̕`��
	m_Player.Render();

}

/**
 * �f�o�b�O�`��
 *
 */
void CGame3::RenderDebug(void) {
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		//�v���C���[�̃f�o�b�O�`��
		m_Player.RenderDebug();
	}
}

/**
*	���
*/
void CGame3::Release(void) {
	//�v���C���[�̉��
	m_Player.Release();
}