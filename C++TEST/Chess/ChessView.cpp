// ChessView.cpp : implementation of the CChessView class
//

#include "stdafx.h"
#include "Chess.h"

#include "ChessDoc.h"
#include "ChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChessView

IMPLEMENT_DYNCREATE(CChessView, CView)

BEGIN_MESSAGE_MAP(CChessView, CView)
	//{{AFX_MSG_MAP(CChessView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChessView construction/destruction

CChessView::CChessView()
{
	// TODO: add construction code here

}

CChessView::~CChessView()
{
}

BOOL CChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CChessView drawing

void CChessView::OnDraw(CDC* pDC)
{
	CChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CChessView printing

BOOL CChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CChessView diagnostics

#ifdef _DEBUG
void CChessView::AssertValid() const
{
	CView::AssertValid();
}

void CChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChessDoc* CChessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChessDoc)));
	return (CChessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChessView message handlers
