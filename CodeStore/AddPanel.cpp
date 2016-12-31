// LookPanel.cpp : 实现文件
//

#include "stdafx.h"
#include "tabdoc.h"
#include "AddPanel.h"
#include ".\addpanel.h"



// CLookPanel

IMPLEMENT_DYNCREATE(CAddPanel, CFormView)

CAddPanel::CAddPanel()
	: CFormView(CAddPanel::IDD)
{
}

CAddPanel::~CAddPanel()
{
}

void CAddPanel::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, m_AddEdit);
}

BEGIN_MESSAGE_MAP(CAddPanel, CFormView)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CLookPanel 诊断

#ifdef _DEBUG
void CAddPanel::AssertValid() const
{
	CFormView::AssertValid();
}

void CAddPanel::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG


// CLookPanel 消息处理程序

void CAddPanel::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	CRect rect;
	CWnd *pChild = GetWindow(GW_CHILD);
	UINT  nID;
	if(!pChild->GetSafeHwnd())return;
	 while(pChild)
	{

		nID = pChild->GetDlgCtrlID();

		pChild->GetWindowRect(&rect);
		ScreenToClient(&rect);

		if(nID == IDC_SAVE)
		{
			rect.left  = cx - rect.Width();
			rect.right = cx;
			pChild->MoveWindow(&rect);
			goto L;
		}

		if(nID == IDC_CURGROUP)
			goto L;
		if(nID == IDC_NAME)
			goto L;
		
		rect.right = rect.left + cx - 6;

		if(pChild == &m_AddEdit)
			rect.bottom = cy;

		pChild->MoveWindow(&rect);
L:
		pChild = pChild->GetWindow(GW_HWNDNEXT);
	}

	SIZE size = {cx,cy};
	if(cx >=5 && cy>= 5)
	SetScaleToFitSize(size);
}

BOOL CAddPanel::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Add your specialized code here and/or call the base class
cs.dwExStyle &=~WS_EX_CLIENTEDGE;
cs.dwExStyle &=~WS_EX_STATICEDGE;
	return CFormView::PreCreateWindow(cs);
}
