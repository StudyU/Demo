// ChessView.h : interface of the CChessView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHESSVIEW_H__C71554E0_E654_4F64_A627_CB9505F2F63C__INCLUDED_)
#define AFX_CHESSVIEW_H__C71554E0_E654_4F64_A627_CB9505F2F63C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChessView : public CView
{
protected: // create from serialization only
	CChessView();
	DECLARE_DYNCREATE(CChessView)

// Attributes
public:
	CChessDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChessView)
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
	virtual ~CChessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChessView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ChessView.cpp
inline CChessDoc* CChessView::GetDocument()
   { return (CChessDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHESSVIEW_H__C71554E0_E654_4F64_A627_CB9505F2F63C__INCLUDED_)
