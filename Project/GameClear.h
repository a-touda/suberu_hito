#pragma once

class CGameClear {
private:
	CTexture				m_BackImage;
	bool					m_bEnd;
	int						m_NextScene;

public:
	CGameClear();
	~CGameClear();
	bool Load(void);
	void Initialize(void);
	void Update(void);
	void Render(void);
	void RenderDebug(void);
	void Release(void);

	int	GetNextScene() { return m_NextScene; }
	bool IsEnd() { return m_bEnd; }
};