#pragma once

#define g_pDeviceManager CDeviceManager::GetInstance()
#define g_pDX9Device	 CDeviceManager::GetInstance()->GetDevice()

class CDeviceManager
{
	Singleton(CDeviceManager);
private:
	LPDIRECT3D9			m_pD3D9;
	LPDIRECT3DDEVICE9	m_pD3D9Device;
public:
	LPDIRECT3DDEVICE9	GetDevice();
	void Destroy();
};