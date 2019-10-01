#pragma once
#include	"Player.h"

class CGame2 {
private:
	bool					m_bEnd;
	int						m_NextScene;
	CTexture				m_Texture;

	//ÉvÉåÉCÉÑÅ[
	CPlayer					 m_Player;

public:
	CGame2();
	~CGame2();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);

	int	GetNextScene() { return m_NextScene; }
	bool IsEnd() { return m_bEnd; }
};
