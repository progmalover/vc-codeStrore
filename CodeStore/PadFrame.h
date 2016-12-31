#pragma once


// CPadFrame 框架
#include "LookPanel.h"
#include "AddPanel.h"
class CPadFrame : public CFrameWnd 
{
	DECLARE_DYNCREATE(CPadFrame)
public:
	CPadFrame();           // 动态创建所使用的受保护的构造函数
	virtual ~CPadFrame();
protected:
	DECLARE_MESSAGE_MAP()
public:
	CSplitterWnd		m_Splitter;
	CLookPanel		m_LookPanel;
	CAddPanel		m_AddPanel;
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


