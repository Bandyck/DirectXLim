// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
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