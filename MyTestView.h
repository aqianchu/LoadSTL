// MyTestView.h : interface of the CMyTestView class
//
/////////////////////////////////////////////////////////////////////////////
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <iostream>
#include <fstream>
#include <string>     // string 与 string.h 完全不同 不可替换
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;

#if !defined(AFX_MYTESTVIEW_H__57ABDA5D_0C80_472B_826D_E959F8E9407F__INCLUDED_)
#define AFX_MYTESTVIEW_H__57ABDA5D_0C80_472B_826D_E959F8E9407F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyTestView : public CView
{
protected: // create from serialization only
	CMyTestView();
	DECLARE_DYNCREATE(CMyTestView)

// Attributes
public:
	CMyTestDoc* GetDocument();
	double x;
	double y;
	double z;
	string line;
	std::vector<string>vertices;
	std::vector<string>Tken;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawScene(void);
	void Init();
	BOOL bSetupPixelFormat(void);
	CClientDC *m_pDC;
	virtual ~CMyTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyTestView)
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyTestView.cpp
inline CMyTestDoc* CMyTestView::GetDocument()
   { return (CMyTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTESTVIEW_H__57ABDA5D_0C80_472B_826D_E959F8E9407F__INCLUDED_)
