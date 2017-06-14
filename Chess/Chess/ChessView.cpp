// ChessView.cpp : CChessView 类的实现
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CChessView 构造/析构

CChessView::CChessView()
{
	// TODO: 在此处添加构造代码

}

CChessView::~CChessView()
{
}

BOOL CChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CChessView 绘制

void CChessView::OnDraw(CDC* pDC)
{
	CChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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


// CChessView 打印

BOOL CChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// CChessView 诊断

#ifdef _DEBUG
void CChessView::AssertValid() const
{
	CView::AssertValid();
}

void CChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChessDoc* CChessView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChessDoc)));
	return (CChessDoc*)m_pDocument;
}
#endif //_DEBUG


// CChessView 消息处理程序

void CChessView::OnPaint()
{
	if (IsIconic())
	{
		//保持不变
	}
	else
	{   
		CRect   rc;
		GetClientRect( &rc );// 获取客户区
		CPaintDC dc(this);
		dc.FillSolidRect(&rc, RGB(0,160,0));   // 填充客户区颜色
		CChessView::OnPaint();           
	}
	
}