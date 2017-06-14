// ChessView.cpp : CChessView ���ʵ��
//

#include "stdafx.h"
#include "Chess.h"

#include "ChessDoc.h"
#include "ChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChessView

IMPLEMENT_DYNCREATE(CChessView, CView)

BEGIN_MESSAGE_MAP(CChessView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CChessView ����/����

CChessView::CChessView()
{
	// TODO: �ڴ˴���ӹ������

}

CChessView::~CChessView()
{
}

BOOL CChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CChessView ����

void CChessView::OnDraw(CDC* pDC)
{
	CChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	static int i = 0;

	if ( i==0 )
	{
		m_chessboard.LoadBitmap(IDB_CHESSBOARD);
		Chessboard.CreateCompatibleDC(pDC);
		Chessboard.SelectObject(m_chessboard);
		m_begin.LoadBitmap(IDB_BEGIN);
		Begin.CreateCompatibleDC(pDC);
		Begin.SelectObject(m_begin);
		m_back.LoadBitmap(IDB_BACK);
		Back.CreateCompatibleDC(pDC);
		Back.SelectObject(m_back);
		m_peace.LoadBitmap(IDB_PEACE);
		Peace.CreateCompatibleDC(pDC);
		Peace.SelectObject(m_peace);
		m_over.LoadBitmap(IDB_OVER);
		Over.CreateCompatibleDC(pDC);
		Over.SelectObject(m_over);
		i = 1;
	}

	pDC->BitBlt(0, 0, 800, 600, &Chessboard, 0, 0, SRCCOPY);
	pDC->BitBlt(600, 100, 800, 600, &Peace, 0, 0, SRCCOPY);
	pDC->BitBlt(600, 200, 800, 600, &Back, 0, 0, SRCCOPY);
	pDC->BitBlt(600, 300, 800, 600, &Begin, 0, 0, SRCCOPY);
	pDC->BitBlt(600, 400, 800, 600, &Over, 0, 0, SRCCOPY);
}


// CChessView ��ӡ

BOOL CChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CChessView ���

#ifdef _DEBUG
void CChessView::AssertValid() const
{
	CView::AssertValid();
}

void CChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChessDoc* CChessView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChessDoc)));
	return (CChessDoc*)m_pDocument;
}
#endif //_DEBUG


// CChessView ��Ϣ�������

void CChessView::OnPaint()
{
	if (IsIconic())
	{
		//���ֲ���
	}
	else
	{   
		CRect   rc;
		GetClientRect( &rc );// ��ȡ�ͻ���
		CPaintDC dc(this);
		dc.FillSolidRect(&rc, RGB(0,160,0));   // ���ͻ�����ɫ
		CChessView::OnPaint();           
	}
	
}