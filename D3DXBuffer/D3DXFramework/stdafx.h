// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
// >> :
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

extern HWND g_hWnd;

#define Singleton(class_name) \
		private : \
			class_name(void); \
			~class_name(void); \
		public : \
			static class_name* GetInstance() \
			{	\
				static class_name instance ; \
				return &instance ; \
			}

#define SafeRelease(p)	{ if(p) p->Release() ; p = NULL ; }
#define SafeDelete(p)	{ if(p) delete p ; p = NULL ; }

struct ST_P_VERTEX
{
	D3DXVECTOR3	p;
	enum { FVF = D3DFVF_XYZ };
};

#include "DeviceManager.h"