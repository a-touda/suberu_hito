#include	"GameApp.h"
#include	"Title.h"
#include	"GameDefine.h"



/**
 * �R���X�g���N�^
 *
 */
CTitle::CTitle() {
}

/**
 * �f�X�g���N�^
 *
 */
CTitle::~CTitle() {
}

/**
*	�ǂݍ���
*	���p����e�N�X�`����ǂݍ���
*/
bool CTitle::Load(void) {
	//�e�N�X�`���̓ǂݍ���
	if (!m_Texture.Load(""))
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
void CTitle::Initialize(void) {
	m_bEnd = false;
}

/**
 * �X�V
 *
 */
void CTitle::Update(void) {
	//Enter�L�[�ŃQ�[���I����ʂ�
	if (g_pInput->IsKeyPush(MOFKEY_RETURN))
	{
		m_bEnd = true;
		m_NextScene = SCENENO_GAMESELECT;
	}
}

/**
 * �`��
 *
 */
void CTitle::Render(void) {
	CGraphicsUtilities::RenderString(10, 10, "�^�C�g�����");
	CGraphicsUtilities::RenderString(10, 40, "Enter�L�[�ŉ�ʑJ��");
}

/**
*	���
*/
void CTitle::Release(void) {
}