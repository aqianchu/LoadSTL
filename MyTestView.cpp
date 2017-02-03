// MyTestView.cpp : implementation of the CMyTestView class
//

#include "stdafx.h"
#include "MyTest.h"

#include "MyTestDoc.h"
#include "MyTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTestView

IMPLEMENT_DYNCREATE(CMyTestView, CView)

BEGIN_MESSAGE_MAP(CMyTestView, CView)
	//{{AFX_MSG_MAP(CMyTestView)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTestView construction/destruction

CMyTestView::CMyTestView()
{
	// TODO: add construction code here
	line="";
	vector<float>vertices(10000,0);

}

CMyTestView::~CMyTestView()
{
}

BOOL CMyTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;//Tramp
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyTestView drawing

void CMyTestView::OnDraw(CDC* pDC)
{
	CMyTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	DrawScene();
}

/////////////////////////////////////////////////////////////////////////////
// CMyTestView printing

BOOL CMyTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyTestView diagnostics

#ifdef _DEBUG
void CMyTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMyTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyTestDoc* CMyTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyTestDoc)));
	return (CMyTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyTestView message handlers

void CMyTestView::OnDestroy() 
{
	HGLRC  hrc;
	hrc = ::wglGetCurrentContext();
	::wglMakeCurrent(NULL, NULL);
	if (hrc)
	::wglDeleteContext(hrc);
	if (m_pDC)
	delete m_pDC;
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

BOOL CMyTestView::bSetupPixelFormat()
{
	/*�� �� �� �� �� �� �� ʽ */  

PIXELFORMATDESCRIPTOR pfd = { 

sizeof(PIXELFORMATDESCRIPTOR),    // pfd�ṹ�Ĵ�С 

1,                                // �汾�� 

PFD_DRAW_TO_WINDOW |              // ֧���ڴ����л�ͼ 

PFD_SUPPORT_OPENGL |              // ֧�� OpenGL 

PFD_TYPE_RGBA,                  // RGBA ��ɫģʽ 

24,                               // 24 λ��ɫ��� 

0, 0, 0, 0, 0, 0,                 // ������ɫλ 

0,                                // û�з�͸���Ȼ��� 

0,                                // ������λλ 

0,                                // ���ۼӻ��� 

0, 0, 0, 0,                       // �����ۼ�λ 

32,                               // 32 λ��Ȼ���     

0,                                // ��ģ�建�� 

0,                                // �޸������� 

PFD_MAIN_PLANE,                   // ���� 

0,                                // ���� 

0, 0, 0                           // ���Բ�,�ɼ��Ժ������ģ

};  

int pixelformat;


if ( (pixelformat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd)) == 0 )

{

MessageBox(_T("ChoosePixelFormat failed"));

return FALSE;

}


if (SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd) == FALSE)

{

MessageBox(_T("SetPixelFormat failed"));

return FALSE;

}

return TRUE;



}

void CMyTestView::Init()
{
	PIXELFORMATDESCRIPTOR pfd;

int n;

HGLRC hrc;

m_pDC = new CClientDC(this);

ASSERT(m_pDC != NULL);

if (!bSetupPixelFormat())

return;

n = ::GetPixelFormat(m_pDC->GetSafeHdc());

::DescribePixelFormat(m_pDC->GetSafeHdc(), n, sizeof(pfd), &pfd);

hrc = wglCreateContext(m_pDC->GetSafeHdc());

wglMakeCurrent(m_pDC->GetSafeHdc(), hrc);



}

int CMyTestView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	Init();
	return 0;
}

void CMyTestView::DrawScene()
{
	ifstream ifs;
	ifs.open("3.stl");

	while(std::getline(ifs,line))
	{
		char *Del=" ";
		char buff[60];
		strcpy(buff,line.c_str());
	
		char* token=strtok(buff,Del);  //�ֽ��ַ���Ϊһ���Ǵ�
		while(token){
			Tken.push_back(token);
			token=strtok(NULL,Del);
		}
	}

	ifs.close();


//string vett=Tken[25390];
//int verr=Tken.size();
for(int i=0;i<Tken.size();i++)
{
	if(stricmp(Tken[i].c_str(), "vertex")==0)  //�ж϶�ȡ���Ƿ�Ϊ������Ϣ
	{
	//	double x=atof(Tken[i+1].c_str());  //���ַ���ת���ɸ�����
	//	double y=atof(Tken[i+2].c_str());
	//	double z=atof(Tken[i+3].c_str());
		vertices.push_back(Tken[i+1]);
		vertices.push_back(Tken[i+2]);
		vertices.push_back(Tken[i+3]);
	}

}

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glPushMatrix();
//string veoo=vertices[11];
int sizeofvert=vertices.size();
for(int j=0;j<sizeofvert;j=j+9)
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex3f(atof(vertices[j].c_str())/20,atof(vertices[j+1].c_str())/20,atof(vertices[j+2].c_str())/20);
	glColor3f(0.0f,1.0f,0.0f);
	glVertex3f(atof(vertices[j+3].c_str())/20,atof(vertices[j+4].c_str())/20,atof(vertices[j+5].c_str())/20);
	glColor3f(0.0f,0.0f,1.0f);
	glVertex3f(atof(vertices[j+6].c_str())/20,atof(vertices[j+7].c_str())/20,atof(vertices[j+8].c_str())/20);
	glEnd();
}

//��������

//glColor3f(0.25,0.36,0.85);

//glutWireSphere(1.0,20,16);

//�����������������
/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear Screen And Depth Buffer

    glLoadIdentity();                                   // Reset The Current Modelview Matrix

    glTranslatef(-1.5f,0.0f,-6.0f);                     // Move Left 1.5 Units And Into The Screen 6.0

    glRotatef(30,0.0f,1.0f,0.0f);                       // Rotate The Triangle On The Y axis ( NEW )

    glBegin(GL_TRIANGLES);                              // Start Drawing A Triangle

    glColor3f(1.0f,0.0f,0.0f);                      // Red

    glVertex3f( 0.0f, 1.0f, 0.0f);                  // Top Of Triangle (Front)

    glColor3f(0.0f,1.0f,0.0f);                      // Green

    glVertex3f(-1.0f,-1.0f, 1.0f);                  // Left Of Triangle (Front)

    glColor3f(0.0f,0.0f,1.0f);                      // Blue

    glVertex3f( 1.0f,-1.0f, 1.0f);                  // Right Of Triangle (Front)

    glColor3f(1.0f,0.0f,0.0f);                      // Red

    glVertex3f( 0.0f, 1.0f, 0.0f);                  // Top Of Triangle (Right)

    glColor3f(0.0f,0.0f,1.0f);                      // Blue

    glVertex3f( 1.0f,-1.0f, 1.0f);                  // Left Of Triangle (Right)

    glColor3f(0.0f,1.0f,0.0f);                      // Green

    glVertex3f( 1.0f,-1.0f, -1.0f);                 // Right Of Triangle (Right)

    glColor3f(1.0f,0.0f,0.0f);                      // Red

    glVertex3f( 0.0f, 1.0f, 0.0f);                  // Top Of Triangle (Back)

    glColor3f(0.0f,1.0f,0.0f);                      // Green

    glVertex3f( 1.0f,-1.0f, -1.0f);                 // Left Of Triangle (Back)

    glColor3f(0.0f,0.0f,1.0f);                      // Blue

    glVertex3f(-1.0f,-1.0f, -1.0f);                 // Right Of Triangle (Back)

    glColor3f(1.0f,0.0f,0.0f);                      // Red

    glVertex3f( 0.0f, 1.0f, 0.0f);                  // Top Of Triangle (Left)

    glColor3f(0.0f,0.0f,1.0f);                      // Blue

    glVertex3f(-1.0f,-1.0f,-1.0f);                  // Left Of Triangle (Left)

    glColor3f(0.0f,1.0f,0.0f);                      // Green

    glVertex3f(-1.0f,-1.0f, 1.0f);                  // Right Of Triangle (Left)

    glEnd();                                            // Done Drawing The Pyramid

 

    glLoadIdentity();                                   // Reset The Current Modelview Matrix

    glTranslatef(1.5f,0.0f,-7.0f);                      // Move Right 1.5 Units And Into The Screen 7.0

    glRotatef(25,1.0f,1.0f,1.0f);                   // Rotate The Quad On The X axis ( NEW )

    glBegin(GL_QUADS);                                  // Draw A Quad

    glColor3f(0.0f,1.0f,0.0f);                      // Set The Color To Green

    glVertex3f( 1.0f, 1.0f,-1.0f);                  // Top Right Of The Quad (Top)

    glVertex3f(-1.0f, 1.0f,-1.0f);                  // Top Left Of The Quad (Top)

    glVertex3f(-1.0f, 1.0f, 1.0f);                  // Bottom Left Of The Quad (Top)

    glVertex3f( 1.0f, 1.0f, 1.0f);                  // Bottom Right Of The Quad (Top)

    glColor3f(1.0f,0.5f,0.0f);                      // Set The Color To Orange

    glVertex3f( 1.0f,-1.0f, 1.0f);                  // Top Right Of The Quad (Bottom)

    glVertex3f(-1.0f,-1.0f, 1.0f);                  // Top Left Of The Quad (Bottom)

    glVertex3f(-1.0f,-1.0f,-1.0f);                  // Bottom Left Of The Quad (Bottom)

    glVertex3f( 1.0f,-1.0f,-1.0f);                  // Bottom Right Of The Quad (Bottom)

    glColor3f(1.0f,0.0f,0.0f);                      // Set The Color To Red

    glVertex3f( 1.0f, 1.0f, 1.0f);                  // Top Right Of The Quad (Front)

    glVertex3f(-1.0f, 1.0f, 1.0f);                  // Top Left Of The Quad (Front)

    glVertex3f(-1.0f,-1.0f, 1.0f);                  // Bottom Left Of The Quad (Front)

    glVertex3f( 1.0f,-1.0f, 1.0f);                  // Bottom Right Of The Quad (Front)

    glColor3f(1.0f,1.0f,0.0f);                      // Set The Color To Yellow

    glVertex3f( 1.0f,-1.0f,-1.0f);                  // Top Right Of The Quad (Back)

    glVertex3f(-1.0f,-1.0f,-1.0f);                  // Top Left Of The Quad (Back)

    glVertex3f(-1.0f, 1.0f,-1.0f);                  // Bottom Left Of The Quad (Back)

    glVertex3f( 1.0f, 1.0f,-1.0f);                  // Bottom Right Of The Quad (Back)

    glColor3f(0.0f,0.0f,1.0f);                      // Set The Color To Blue

    glVertex3f(-1.0f, 1.0f, 1.0f);                  // Top Right Of The Quad (Left)

    glVertex3f(-1.0f, 1.0f,-1.0f);                  // Top Left Of The Quad (Left)

    glVertex3f(-1.0f,-1.0f,-1.0f);                  // Bottom Left Of The Quad (Left)

    glVertex3f(-1.0f,-1.0f, 1.0f);                  // Bottom Right Of The Quad (Left)

    glColor3f(1.0f,0.0f,1.0f);                      // Set The Color To Violet

    glVertex3f( 1.0f, 1.0f,-1.0f);                  // Top Right Of The Quad (Right)

    glVertex3f( 1.0f, 1.0f, 1.0f);                  // Top Left Of The Quad (Right)

    glVertex3f( 1.0f,-1.0f, 1.0f);                  // Bottom Left Of The Quad (Right)

    glVertex3f( 1.0f,-1.0f,-1.0f);                  // Bottom Right Of The Quad (Right)

    glEnd();                                            // Done Drawing The Quad

*/

glPopMatrix();

glFinish();

SwapBuffers(wglGetCurrentDC());

}

void CMyTestView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	int w,h;

w = cx;

h = cy;

if(h == 0)

h = 1;

float ratio = 1.0* w / h;

glMatrixMode(GL_PROJECTION); //���޸�ǰ��������ϵ

glLoadIdentity();

// Set the viewport�ӿ� to be the entire window

glViewport(0, 0, w, h);

gluPerspective(45,ratio,1,1000); 

glMatrixMode(GL_MODELVIEW);

glLoadIdentity();

gluLookAt(0.0,0.0,5.0, 0.0,0.0,-1.0, 0.0f,1.0f,0.0f);


	
}

