#pragma once
class CMesh
{
public:
	CMesh();
	~CMesh();
private:
	IDirect3DVertexBuffer9*	m_pV;
public:
	void Setup();
	void Render();
};