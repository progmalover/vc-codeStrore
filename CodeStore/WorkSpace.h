#pragma once
#include "CMyControlBar.h"

class CWorkSpace :
	public CMyControlBar
{

    DECLARE_DYNAMIC(CWorkSpace)
public:
	CWorkSpace(void);
	~CWorkSpace(void);

public:
	 CTreeCtrl    m_TypeTree;
protected: 
	DECLARE_MESSAGE_MAP()
	 afx_msg void OnFileNew();
public:
	 virtual BOOL  Create(CWnd* pParentWnd, UINT nID, LPCTSTR lpszWindowName, CSize sizeDefault , DWORD dwStyle = WS_CHILD|WS_VISIBLE|CBRS_TOP);
//	 afx_msg void OnSize(UINT nType, int cx, int cy);
	 afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
	 void ShowWorkSpace(bool enable);
	 CWnd * ShowFloatFrame(BOOL enable);
//	 afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	 afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	 void LoadTypeStore(void);
};
