// tabdoc.h : tabdoc Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error �ڰ������� PCH �Ĵ��ļ�֮ǰ������stdafx.h�� 
#endif

#include "resource.h"       // ������


// CtabdocApp:
// �йش����ʵ�֣������ tabdoc.cpp
//

class CtabdocApp : public CWinApp
{
public:
	CtabdocApp();

public:
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	CFrameWnd * AppGetMainForame(void);
//	virtual BOOL OnIdle(LONG lCount);
//	virtual BOOL LoadSysPolicies();
};

extern CtabdocApp theApp;
