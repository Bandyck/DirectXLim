#include "stdafx.h"
#include "DeviceManager.h"

CDeviceManager::CDeviceManager()
	: m_pD3D9(NULL)
	, m_pD3D9Device(NULL)
{
	// �������̽� ����
	m_pD3D9 = Direct3DCreate9(D3D_SDK_VERSION);

	// ���ؽ� ���μ��� Ȯ��
	D3DCAPS9	caps;
	int			nVertexProcessing;

	m_pD3D9->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;	// �׷��� ī��
	else
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;	// CPU

	// ����ü ä���
	D3DPRESENT_PARAMETERS	D3D9pp;
	ZeroMemory(&D3D9pp, sizeof(D3DPRESENT_PARAMETERS));

	D3D9pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	D3D9pp.Windowed = TRUE;
	D3D9pp.BackBufferFormat = D3DFMT_UNKNOWN;
	D3D9pp.EnableAutoDepthStencil = TRUE;
	D3D9pp.AutoDepthStencilFormat = D3DFMT_D16;

	// ����̽� ����
	m_pD3D9->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		g_hWnd,
		nVertexProcessing,
		&D3D9pp,
		&m_pD3D9Device
	);
}

CDeviceManager::~CDeviceManager()
{

}

LPDIRECT3DDEVICE9 CDeviceManager::GetDevice()
{
	return m_pD3D9Device;
}

void CDeviceManager::Destroy()
{
	SafeRelease(m_pD3D9Device);
	SafeRelease(m_pD3D9);
}