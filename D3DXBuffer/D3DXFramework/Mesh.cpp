#include "stdafx.h"
#include "Mesh.h"

CMesh::CMesh()
	: m_pV(NULL)
{
}

CMesh::~CMesh()
{
	SafeRelease(m_pV);
}

void CMesh::Setup()
{
	g_pDX9Device->CreateVertexBuffer(
		3 * sizeof(ST_P_VERTEX),
		D3DUSAGE_WRITEONLY,
		ST_P_VERTEX::FVF,
		D3DPOOL_MANAGED,
		&m_pV,
		0
	);

	ST_P_VERTEX* pV = NULL;

	m_pV->Lock(0, 0, (LPVOID*)&pV, 0);

	pV[0].p = D3DXVECTOR3(-1.0f, 0.0f, 2.0f);
	pV[1].p = D3DXVECTOR3( 0.0f, 1.0f, 2.0f);
	pV[2].p = D3DXVECTOR3( 1.0f, 0.0f, 2.0f);

	m_pV->Unlock();

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16	matProj;
	D3DXMatrixPerspectiveFovLH(
		&matProj,
		D3DX_PI / 2.0F,
		rc.right / (float)rc.bottom,
		1.0f,
		1000.0f
	);
	g_pDX9Device->SetTransform(D3DTS_PROJECTION, &matProj);
}

void CMesh::Render()
{
	g_pDX9Device->SetStreamSource(0, m_pV, 0, sizeof(ST_P_VERTEX));
	g_pDX9Device->SetFVF(ST_P_VERTEX::FVF);
	g_pDX9Device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
}