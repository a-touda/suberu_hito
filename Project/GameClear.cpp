#include	"GameDefine.h"
#include	"GameClear.h"

//�ύX����V�[��(�O���Q�ƁA���̂�GameApp.cpp)
extern int		gChangeScene;

CFont			gFont2;
/**
 * �R���X�g���N�^
 *
 */
CGameClear::CGameClear() :
	m_BackImage() {
}

/**
 * �f�X�g���N�^
 *
 */
CGameClear::~CGameClear() {
}

/**
 * �ǂݍ���
 * ���p����e�N�X�`����ǂݍ��ށB
 */
bool CGameClear::Load(void) {
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
void CGameClear::Initialize(void) {
	m_bEnd = false;

	gFont2.Create(80, "");
}

/**
 * �X�V
 *
 */
void CGameClear::Update(void) {

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
void CGameClear::Render(void) {
	m_BackImage.Render(0, 0);
	CGraphicsUtilities::RenderString(10, 10, "�Q�[���N���A���");
	gFont2.RenderString(430, 100, "GameClear!");
	CGraphicsUtilities::RenderString(520, 300, MOF_COLOR_WHITE, "Press Enter Key");
}

/**
 * �f�o�b�O�`��
 *
 */
void CGameClear::RenderDebug(void) {
}

/**
 * ���
 *
 */
void CGameClear::Release(void) {

	//�e�N�X�`���̉��
	m_BackImage.Release();

	//�t�H���g�̉��
	gFont2.Release();
}