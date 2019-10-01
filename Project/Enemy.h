#pragma once
#include	"Mof.h"

//�����蔻�茸����
#define		ENEMY_RECTDECREASE		10

class CEnemy {
private:
	CTexture*				m_pTexture;
	CSpriteMotionController	m_Motion;
	int						m_Type;
	float					m_PosX;
	float					m_PosY;
	float					m_MoveX;
	float					m_MoveY;
	bool					m_bShow;
	bool					m_bWReverse;
	bool					m_bHReverse;
	CRectangle				m_SrcRect;
	int						m_HP;
	int						m_DamageWait;

	//�����[�V������ޒ�`

public:
	CEnemy();
	~CEnemy();
	void Initialize(float px, float py, int type);
	void Update(void);
	void CollisionStage(float ox, float oy);
	void Render(float wx, float wy);
	void RenderDebug(float wx, float wy);
	void Release(void);
	void SetTexture(CTexture* pt) { m_pTexture = pt; }
	bool GetShow(void) { return m_bShow; }
	CRectangle GetRect() {
		return CRectangle(m_PosX + ENEMY_RECTDECREASE, m_PosY + ENEMY_RECTDECREASE, m_PosX + m_SrcRect.GetWidth() - ENEMY_RECTDECREASE, m_PosY + m_SrcRect.GetHeight());
	}
	void Damage(int dmg, bool bRev);
	int GetDamageWait(void) { return m_DamageWait; }
};

//�G�t�F�N�g�����[�V�����̕����͂܂������ĂȂ�