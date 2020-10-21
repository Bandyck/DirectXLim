#pragma once
class CMesh;
class CMainGame
{
public:
	CMainGame();
	~CMainGame();
private:
	CMesh*	m_pMesh;
public:
	void Setup();
	void Update();
	void Render();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};