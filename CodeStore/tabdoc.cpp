// tabdoc.cpp : ����Ӧ�ó��������Ϊ��
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
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	//ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CtabdocApp ����

CtabdocApp::CtabdocApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CtabdocApp ����

CtabdocApp theApp;

// CtabdocApp ��ʼ��
CMainFrame  *pMainFrame;
BOOL CtabdocApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControls()�����򣬽��޷��������ڡ�
	InitCommonControls();
    AfxInitRichEdit2();

	CWinApp::InitInstance();

	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	//CMainFrame  *pMainFrame;
    pMainFrame = new CMainFrame();
	pMainFrame->LoadFrame(IDR_MAINFRAME);
	m_pMainWnd = pMainFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	//pMainFrame->pPadFrame->m_LookPanel.InitHelper();
	// �������ں�׺ʱ�ŵ��� DragAcceptFiles��
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand  ֮����

	extern CPadFrame *pPadFrame;
	// TODO: �ڴ����ר�ô����/����û���
	pPadFrame->m_LookPanel.InitHelper();
	return TRUE;
}



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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

// �������жԻ����Ӧ�ó�������
void CtabdocApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CtabdocApp ��Ϣ�������


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
