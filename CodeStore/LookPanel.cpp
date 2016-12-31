// AddPanel.cpp : 实现文件
//

#include "stdafx.h"
#include "tabdoc.h"
#include "LookPanel.h"
#include ".\lookpanel.h"



// CAddPanel

IMPLEMENT_DYNCREATE(CLookPanel, CFormView)

CLookPanel::CLookPanel()
	: CFormView(CLookPanel::IDD)
{
}

CLookPanel::~CLookPanel()
{
}

void CLookPanel::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CODEVIEW, m_ViewEdit);
	 
}

BEGIN_MESSAGE_MAP(CLookPanel, CFormView)
	ON_WM_SIZE()
	ON_WM_CREATE()
	 
END_MESSAGE_MAP()


// CAddPanel 诊断

#ifdef _DEBUG
void CLookPanel::AssertValid() const
{
	CFormView::AssertValid();
}

void CLookPanel::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG


// CAddPanel 消息处理程序

void CLookPanel::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
    
	//GW_HWNDNEXT
	CRect rect;
	CWnd  *pChild = GetWindow(GW_CHILD);
	
	if(!pChild->GetSafeHwnd()|| cx<=6 ||cy<=6)return;
    while(pChild)
	{
		pChild->GetWindowRect(&rect);
		ScreenToClient(&rect);

		rect.right = rect.left + cx - 6;

		if(pChild == &m_ViewEdit)
			rect.bottom = cy;
		pChild->MoveWindow(&rect);
		pChild = pChild->GetWindow(GW_HWNDNEXT);
	}
	// TODO: 在此处添加消息处理程序代码


	SIZE size = {cx,cy};

	if(cx >=5 && cy>= 5)
	SetScaleToFitSize(size);
}


 
int CLookPanel::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

  
	return 0;
}

char *gColumnLabel[] = 
{
	"相关内容",
	"附加信息"
};

const int NUM_COLUMNS = 2;
bool CLookPanel::InitHelper(void)
{

	LV_COLUMN  lvc;

	if(!IsWindow(this->m_hWnd)) return false;
	CListCtrl *pList =(CListCtrl *) GetDlgItem(IDC_HITITEMS);
	
	if(!pList ) return false;

	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
    pList->SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	for(int i = 0; i<NUM_COLUMNS; i++)
	{
		lvc.iSubItem = i;
		lvc.pszText = gColumnLabel[i];
		lvc.cx = 80;
		lvc.fmt = LVCFMT_LEFT;
		pList->InsertColumn(i,&lvc);
	}

	return true;
}


//void CLookPanel::OnInitialUpdate()
//{
//	CFormView::OnInitialUpdate();
//    
//	InitHelper();
//}

//void CLookPanel::PreSubclassWindow()
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//	CFormView::PreSubclassWindow();
//}

void CLookPanel::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
    static bool  hitlistinit;
    if(!hitlistinit)
		hitlistinit = InitHelper();
}

BOOL CLookPanel::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Add your specialized code here and/or call the base class
cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
cs.dwExStyle &= ~WS_EX_STATICEDGE;
	return CFormView::PreCreateWindow(cs);
}
