// MainFrm.h : CMainFrame 类的接口
//


#pragma once
#include "TabDocTemp.h";
#include "WorkSpace.h"
#include "PadFrame.h"
#include "LookPanel.h"
#include "AddPanel.h"

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建

	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:	
	CMainFrame();
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar		m_wndStatusBar;
	CToolBar		m_wndToolBar;
	CTabDocTemp		m_TabTemp;
	CWorkSpace		m_WorkSpace;
	CImageList		m_ImageList;  
	CMyControlBar   m_CtrlBar;
	
public:

// 生成的消息映射函数
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


