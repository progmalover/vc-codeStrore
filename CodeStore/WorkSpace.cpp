#include "StdAfx.h"
#include ".\workspace.h"
#include "afxpriv.h"
//#include "string"
//using namespace std;
CWorkSpace::CWorkSpace(void)
{
}

CWorkSpace::~CWorkSpace(void)
{
}
BEGIN_MESSAGE_MAP(CWorkSpace, CMyControlBar)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
//	ON_WM_CREATE()
//ON_WM_SIZE()
ON_WM_NCCALCSIZE()
//ON_WM_SHOWWINDOW()
ON_WM_CREATE()
END_MESSAGE_MAP()
IMPLEMENT_DYNAMIC(CWorkSpace, CMyControlBar)
void CWorkSpace::OnFileNew()
{
	// TODO: Add your command handler code here
}


BOOL CWorkSpace:: Create(CWnd * pParentWnd, UINT nID, LPCTSTR lpszWindowName, CSize sizeDefault, DWORD dwStyle)
{
	// TODO: Add your specialized code here and/or call the base class

	int ret = CMyControlBar ::Create(pParentWnd,nID,lpszWindowName,sizeDefault,dwStyle);

	VERIFY(ret != FALSE);
	if(m_TypeTree.Create(WS_VISIBLE | WS_TABSTOP | WS_CHILD | WS_BORDER
		| TVS_HASBUTTONS | TVS_LINESATROOT | TVS_HASLINES
		| TVS_DISABLEDRAGDROP,
		CRect(10, 10, 300, 100), this, 0x1005)!= ret)
	{
			TRACE0("Create Type Tree Failure!\n");
			return -1;
	}
    
   //m_TypeTree.ShowWindow(TRUE);

    return ret;
}


void CWorkSpace::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CMyControlBar::OnNcCalcSize(bCalcValidRects, lpncsp);

	if(m_TypeTree.GetSafeHwnd()!=NULL)
	{

	//由 dock的位置定义大小
		CRect rect0,rect1,rect2;
		GetClientRect(&rect0);

		if(IsFloating())
		{
			rect0.top += 4;
			rect0.left += 4;
			rect0.right -=4;
			rect0.bottom -=4;
			m_TypeTree.MoveWindow(rect0);
			return;
		}

		m_btnClose.GetWindowRect(&rect1);
		ScreenToClient(&rect1);
		rect2 = GetGripperRect();

		switch(m_nDockBarID)
		{
			case AFX_IDW_DOCKBAR_TOP:
			case AFX_IDW_DOCKBAR_BOTTOM:
				{
					rect0.left = rect2.left  + 20;
					rect0.right -= 10;//rect1.right;
					rect0.top += 4;//rect2.bottom + 10;
					rect0.bottom -=4;
				}
				break;
			case AFX_IDW_DOCKBAR_LEFT:
			case AFX_IDW_DOCKBAR_RIGHT:
				{
					rect0.left = rect2.left ;
					rect0.right -= 4;
					rect0.top = rect2.bottom + 20;
					rect0.bottom -= 10;
				}
				break;
		}
		
		m_TypeTree.MoveWindow(rect0);
	}

}

void CWorkSpace::ShowWorkSpace(bool enable)
{
	if(enable)
	{
		if(IsFloating())
			//  ShowFloatFrame(SW_SHOWNORMAL );//->ShowWindow(TRUE);
			m_pDockContext->ToggleDocking();
		
		 ShowWindow(SW_SHOWNORMAL);
	}
	else
	{
		if(IsFloating())
			  ShowFloatFrame(SW_HIDE);//->ShowWindow(FALSE);
		else
			  ShowWindow(FALSE);
	}

}

CWnd * CWorkSpace::ShowFloatFrame(BOOL enable)
{
	CWnd *pWnd = this;;
	 
	pWnd->ShowWindow(enable);
	pWnd = GetParent();
	 
	while(!pWnd->IsKindOf(RUNTIME_CLASS(CMiniDockFrameWnd)))
	{
		
		  pWnd->ShowWindow(enable);
		  pWnd = pWnd->GetParent();
		 
	}
	pWnd->ShowWindow(enable);
	return pWnd;
}


int CWorkSpace::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMyControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	 
	return 0;
}

void CWorkSpace::LoadTypeStore(void)
{
	TVINSERTSTRUCT tvInsert;
	tvInsert.hParent = NULL;
	tvInsert.hInsertAfter = NULL;
	tvInsert.item.mask = TVIF_TEXT;
	tvInsert.item.pszText = _T("All CodeStores");
	HTREEITEM hCountry = m_TypeTree.InsertItem(&tvInsert);


    /*检测系统注册看是否已经存在工作存储文件夹或存储文件*/
    
	/*不存在则提出新建目录和展示类别让用户选择*/

	/*存在则载入*/
 
	BSTR  b = ::SysAllocString(L"Golf is fun!");

    CString  str= "hello world";
    BSTR  a = str.SetSysString(&b);
	//char a[3]={0};
	//sprintf(a,"%c",(char *)b);
	if(a == b)
	MessageBox(str.GetBuffer(),"df",MB_OK);
	
	/*若选择新建*/
}
