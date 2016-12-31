// MainFrm.h : CMainFrame ��Ľӿ�
//


#pragma once
#include "TabDocTemp.h";
#include "WorkSpace.h"
#include "PadFrame.h"
#include "LookPanel.h"
#include "AddPanel.h"

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����

	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:	
	CMainFrame();
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar		m_wndStatusBar;
	CToolBar		m_wndToolBar;
	CTabDocTemp		m_TabTemp;
	CWorkSpace		m_WorkSpace;
	CImageList		m_ImageList;  
	CMyControlBar   m_CtrlBar;
	
public:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFileNew();
	virtual void RecalcLayout(BOOL bNotify = TRUE);

	void CacalLayout(void);

	afx_msg void Ontabdoctype();
	afx_msg void OnUpdatetabdoctype(CCmdUI *pCmdUI);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnClose();
};


