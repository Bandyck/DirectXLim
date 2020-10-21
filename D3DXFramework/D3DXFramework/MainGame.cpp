#include "stdafx.h"
#include "MainGame.h"
#include "DeviceManager.h"

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	g_pDeviceManager->Destroy();
}

void CMainGame::Setup()
{
}

void CMainGame::Update()
{
}

void CMainGame::Render()
{
	g_pDX9Device->Clear(
		NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(34, 177, 76),
		1.0F,
		0
	);
	g_pDX9Device->BeginScene();

	g_pDX9Device->EndScene();
	g_pDX9Device->Present(NULL, NULL, NULL, NULL);
}

void CMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}