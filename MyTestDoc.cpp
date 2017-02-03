// MyTestDoc.cpp : implementation of the CMyTestDoc class
//

#include "stdafx.h"
#include "MyTest.h"

#include "MyTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTestDoc

IMPLEMENT_DYNCREATE(CMyTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyTestDoc, CDocument)
	//{{AFX_MSG_MAP(CMyTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTestDoc construction/destruction

CMyTestDoc::CMyTestDoc()
{
	// TODO: add one-time construction code here

}

CMyTestDoc::~CMyTestDoc()
{
}

BOOL CMyTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyTestDoc serialization

void CMyTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyTestDoc diagnostics

#ifdef _DEBUG
void CMyTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyTestDoc commands
