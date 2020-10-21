#pragma once
class CMainGame
{
public:
	CMainGame();
	~CMainGame();
private:

public:
	void Setup();
	void Update();
	void Render();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};