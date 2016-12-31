// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "tabdoc.h"

#include "MainFrm.h"

#include ".\mainfrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame
CPadFrame  *pPadFrame;
IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
//	ON_COMMAND(ID_VIEW_STATUS_BAR, )
ON_COMMAND(IDR_tabdocTYPE, Ontabdoctype)
ON_UPDATE_COMMAND_UI(IDR_tabdocTYPE, OnUpdatetabdoctype)
//ON_COMMAND(ID_VIEW_TOOLBAR, OnViewToolbar)
//ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR, OnUpdateViewToolbar)
//ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR, OnUpdateViewToolbar)
//ON_UPDATE_COMMAND_UI(ID_VIEW_TOOLBAR, OnUpdateViewToolbar)
ON_WM_ERASEBKGND()
ON_WM_CLOSE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	
	  if (!m_wndToolBar.Create(this,TBSTYLE_FLAT|
		  WS_VISIBLE|CBRS_TOP|TBSTYLE_TOOLTIPS  ) ||
		 !m_wndToolBar.LoadToolBar(IDR_MAINFRAME))

	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}


	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}

	 


	m_ImageList.Create(MAKEINTRESOURCE(IDB_IMAGELIST), 13, 3, RGB(0,255,0));
	m_WorkSpace.SetBtnImageList(&m_ImageList); 

	if (!m_WorkSpace.Create(this, CG_ID_VIEW_WORKSPACE ,
		_T("Workspace"), CSize(120,200)))
	{
		TRACE0("Failed to create dialog bar m_wndWorkspace\n");
		return -1;		// fail to create
	}

	m_WorkSpace.SetBarStyle(m_WorkSpace.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	m_WorkSpace.EnableDocking(CBRS_ALIGN_RIGHT);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_WorkSpace, AFX_IDW_DOCKBAR_RIGHT);

//	m_CtrlBar.Create(this,222333444,MAKEINTRESOURCE(IDB_IMAGELIST));
	m_CtrlBar.SetBtnImageList(&m_ImageList); 

	if (!m_CtrlBar.Create(this, CG_ID_VIEW_WORKSPACE +1 ,
		_T("tty"), CSize(120,200)))
	{
		TRACE0("Failed to create dialog bar m_wndWorkspace\n");
		return -1;		// fail to create
	}

	m_CtrlBar.SetBarStyle(m_WorkSpace.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);

	//m_CtrlBar.SetWindowPos(&wndBottom,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);

	m_CtrlBar.EnableDocking(CBRS_ALIGN_BOTTOM);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_CtrlBar, AFX_IDW_DOCKBAR_BOTTOM);

   // CacalLayout();

	m_TabTemp.ShowWindow(TRUE);

	pPadFrame = new CPadFrame;
	pPadFrame->Create(NULL,"PadFrame",WS_VISIBLE|WS_CHILD,CRect(0,0,0,0),this);
	pPadFrame->ShowWindow(SW_SHOW);

//	this->m_h
	m_WorkSpace.LoadTypeStore();
	
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或
	// 样式
	
   // cs.style |=WS_DLGFRAME   ;// ~WS_THICKFRAME;
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	return TRUE;
}


// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame 消息处理程序


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class
	m_TabTemp.Create(WS_CHILD|WS_VISIBLE |WS_CLIPCHILDREN|
		WS_CLIPSIBLINGS|TCS_FLATBUTTONS  ,CRect(0,0,0,0),this,IDC_TABTEMP);

	

	return CFrameWnd::OnCreateClient(lpcs, pContext);
}

void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	
	CFrameWnd::OnSize(nType, cx, cy);
	//CacalLayout();
}

void CMainFrame::OnFileNew()
{
	
}

void CMainFrame::RecalcLayout(BOOL bNotify)
{
	CFrameWnd::RecalcLayout(bNotify); 
	
	if(bNotify ==1);
	  CacalLayout();
}


void CMainFrame::CacalLayout(void)
{
	if(pPadFrame && ::IsWindow(m_TabTemp.m_hWnd) && ::IsWindow(pPadFrame->m_hWnd))
	{
		CRect  DskRect,usedRect;
		GetClientRect(&DskRect);

		CWnd *pChild;
		pChild = GetWindow(GW_CHILD);
		while(pChild)
		{

			if(pChild->IsWindowVisible() &&(pChild !=  pPadFrame)&&
			(pChild != &m_TabTemp))
			{
				pChild->GetWindowRect(&usedRect);
				ScreenToClient(&usedRect);

				DskRect.SubtractRect(&DskRect,&usedRect);

			}
    			pChild = pChild->GetWindow(GW_HWNDNEXT);
		}

		int bottom = DskRect.bottom ;
		DskRect.bottom = DskRect.top + 29;
		CRect tabRect = DskRect;
		tabRect.DeflateRect(2,2,-1,2);
		m_TabTemp.MoveWindow(&tabRect);


		DskRect.top = DskRect.bottom;
		DskRect.bottom = bottom;
        
	
		pPadFrame->MoveWindow(&DskRect);


	}
	 
}

void CMainFrame::Ontabdoctype()
{
	if(m_WorkSpace.IsWindowVisible())
		 m_WorkSpace.ShowWorkSpace(FALSE);
	else
		 m_WorkSpace.ShowWorkSpace(TRUE);
	
}

void CMainFrame::OnUpdatetabdoctype(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here

	pCmdUI->SetCheck(m_WorkSpace.IsWindowVisible());
		
	pCmdUI->ContinueRouting();
}




BOOL CMainFrame::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CBrush  *pBrush = CBrush::FromHandle(CreateSolidBrush(GetSysColor(COLOR_BTNFACE)));
	
	CRect  clr;
	GetClientRect(&clr);
	pDC->FillRect(&clr,pBrush);
	
	pBrush->DeleteObject();

	
	return TRUE;//CFrameWnd::O
}


void CMainFrame::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    delete pPadFrame;
	CFrameWnd::OnClose();
}
