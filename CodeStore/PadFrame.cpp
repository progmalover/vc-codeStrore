// PadFrame.cpp : 实现文件
//

#include "stdafx.h"
#include "tabdoc.h"
#include "PadFrame.h"
#include ".\padframe.h"

#include "LookPanel.h"
#include "AddPanel.h"
// CPadFrame

IMPLEMENT_DYNCREATE(CPadFrame, CFrameWnd)

CPadFrame::CPadFrame()
{
}

CPadFrame::~CPadFrame()
{
}


BEGIN_MESSAGE_MAP(CPadFrame, CFrameWnd)
//	ON_WM_CREATE()
//ON_WM_CREATE()
ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CPadFrame 消息处理程序
	 
BOOL CPadFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类
	CCreateContext  ccst;

	memset(&ccst,0,sizeof(ccst));

	m_Splitter.CreateStatic(this,1,2);

	pContext = &ccst;

	ccst.m_pNewViewClass = m_LookPanel.GetRuntimeClass();
	m_Splitter.CreateView(0,0,ccst.m_pNewViewClass,CSize(280,20),NULL);
	
    ccst.m_pNewViewClass = m_AddPanel.GetRuntimeClass();
	m_Splitter.CreateView(0,1, ccst.m_pNewViewClass,CSize(20,20),NULL);
	
	return TRUE;
}


BOOL CPadFrame::OnEraseBkgnd(CDC* pDC)
{
	CBrush  Brush ;
	
	Brush.m_hObject = CreateSolidBrush(GetSysColor(COLOR_BTNFACE));
	
	CRect  clr;
	GetClientRect(&clr);
	pDC->FillRect(&clr,&Brush);
	
	Brush.DeleteObject();
	return TRUE;//CFrameWnd::O
}

BOOL CPadFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Add your specialized code here and/or call the base class
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.dwExStyle &=~WS_EX_STATICEDGE;
	return CFrameWnd::PreCreateWindow(cs);
}
