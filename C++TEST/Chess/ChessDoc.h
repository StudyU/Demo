// ChessDoc.h : interface of the CChessDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHESSDOC_H__4AB3B245_294C_48F3_8987_37D01D79A1CF__INCLUDED_)
#define AFX_CHESSDOC_H__4AB3B245_294C_48F3_8987_37D01D79A1CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChessDoc : public CDocument
{
protected: // create from serialization only
	CChessDoc();
	DECLARE_DYNCREATE(CChessDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChessDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChessDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChessDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHESSDOC_H__4AB3B245_294C_48F3_8987_37D01D79A1CF__INCLUDED_)
