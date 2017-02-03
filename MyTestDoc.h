// MyTestDoc.h : interface of the CMyTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTESTDOC_H__8CE20383_3DD0_4569_A8F5_6FA385F8AEE3__INCLUDED_)
#define AFX_MYTESTDOC_H__8CE20383_3DD0_4569_A8F5_6FA385F8AEE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyTestDoc : public CDocument
{
protected: // create from serialization only
	CMyTestDoc();
	DECLARE_DYNCREATE(CMyTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTESTDOC_H__8CE20383_3DD0_4569_A8F5_6FA385F8AEE3__INCLUDED_)
