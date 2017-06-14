// ChessView.h : CChessView ��Ľӿ�
//


#pragma once


class CChessView : public CView
{
protected: // �������л�����
	CChessView();
	DECLARE_DYNCREATE(CChessView)

// ����
public:
	CChessDoc* GetDocument() const;

// ����
public:
	CDC Chessboard;
	CDC Begin;
	CDC Peace;
	CDC Over;
	CDC Back;
	CBitmap m_chessboard;
	CBitmap m_begin;
	CBitmap m_peace;
	CBitmap m_over;
	CBitmap m_back;



// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual void OnPaint();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CChessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ChessView.cpp �еĵ��԰汾
inline CChessDoc* CChessView::GetDocument() const
   { return reinterpret_cast<CChessDoc*>(m_pDocument); }
#endif

