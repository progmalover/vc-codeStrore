// tabdoc.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "tabdoc.h"
#include "MainFrm.h"
#include ".\tabdoc.h"

//#include "tabdocDoc.h"
//#include "tabdocView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtabdocApp

BEGIN_MESSAGE_MAP(CtabdocApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	//ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CtabdocApp 构造

CtabdocApp::CtabdocApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CtabdocApp 对象

CtabdocApp theApp;

// CtabdocApp 初始化
CMainFrame  *pMainFrame;
BOOL CtabdocApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControls()。否则，将无法创建窗口。
	InitCommonControls();
    AfxInitRichEdit2();

	CWinApp::InitInstance();

	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，

	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	//CMainFrame  *pMainFrame;
    pMainFrame = new CMainFrame();
	pMainFrame->LoadFrame(IDR_MAINFRAME);
	m_pMainWnd = pMainFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	//pMainFrame->pPadFrame->m_LookPanel.InitHelper();
	// 仅当存在后缀时才调用 DragAcceptFiles，
	//  在 SDI 应用程序中，这应在 ProcessShellCommand  之后发生

	extern CPadFrame *pPadFrame;
	// TODO: 在此添加专用代码和/或调用基类
	pPadFrame->m_LookPanel.InitHelper();
	return TRUE;
}



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton2();
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void CtabdocApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CtabdocApp 消息处理程序


CFrameWnd * CtabdocApp::AppGetMainForame(void)
{
	return (CFrameWnd *)m_pMainWnd;
}

//BOOL CtabdocApp::LoadSysPolicies()
//{
//
//	return CWinApp::LoadSysPolicies();
//}

void CAboutDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
    SendMessage(WM_NCLBUTTONDOWN,HTCAPTION,0);

	
	CDialog::OnLButtonDown(nFlags, point);
}

void CAboutDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//OnOK();
	CWnd *p = (CWnd *)GetDlgItem(IDC_BUTTON2);

	p->ShowWindow(SW_SHOW);
}

void CAboutDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CFontDialog  cfd;
	cfd.DoModal();

	LOGFONT  ft;
	HFONT hft;
	
	cfd.GetCurrentFont(&ft);
	hft = CreateFontIndirect(&ft);
	
	CFont *f = CFont::FromHandle(hft);
    CDC *pdc = GetDC();
	pdc->SaveDC();

	pdc->SelectObject(f);
	pdc->SetBkMode(TRANSPARENT);
	pdc->TextOut(0,0,"this is an example");

	pdc->RestoreDC(0);
	ReleaseDC(pdc);
	DeleteObject(hft);


}
