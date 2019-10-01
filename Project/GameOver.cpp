#include	"GameDefine.h"
#include	"GameOver.h"

//�ύX����V�[��(�O���Q�ƁA���̂�GameApp.cpp)
extern int						gChangeScene;

/**
 * �R���X�g���N�^
 *
 */
CGameOver::CGameOver() :
	m_BackImage() {
}

/**
 * �f�X�g���N�^
 *
 */
CGameOver::~CGameOver() {
}

/**
 * �ǂݍ���
 * ���p����e�N�X�`����ǂݍ��ށB
 */
bool CGameOver::Load(void) {
	//�e�N�X�`���̓Ǎ���
	if (!m_BackImage.Load(""))
	{
		return false;
	}
	return true;
}

/**
 * ������
 * �p�����[�^�[����W������������B
 * ��Ԃ��������������Ƃ��Ɏ��s����B
 */
void CGameOver::Initialize(void) {
	m_bEnd = false;
}

/**
 * �X�V
 *
 */
void CGameOver::Update(void) {

	//Enter�L�[�ŃX�e�[�W�I����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		gChangeScene = SCENENO_GAMESELECT;
	}
}

/**
 * �`��
 *
 */
void CGameOver::Render(void) {
	m_BackImage.Render(0, 0);
	CGraphicsUtilities::RenderString(10, 10, "�Q�[���I�[�o�[���");
	CGraphicsUtilities::RenderString(520, 300, MOF_COLOR_WHITE, "Press Enter Key");
}

/**
 * �f�o�b�O�`��
 *
 */
void CGameOver::RenderDebug(void) {
}

/**
 * ���
 *
 */
void CGameOver::Release(void) {

	//�e�N�X�`���̉��
	m_BackImage.Release();
}