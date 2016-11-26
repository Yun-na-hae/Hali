
// HalliGalliView.h : CHalliGalliView 클래스의 인터페이스
//

#pragma once
#include "afxwin.h"


class CHalliGalliView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CHalliGalliView();
	DECLARE_DYNCREATE(CHalliGalliView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_HALLIGALLI_FORM };
#endif

// 특성입니다.
public:
	CHalliGalliDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CHalliGalliView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedIdPreviewNext();
	afx_msg void OnStnClickedP2cards();
	CStatic m_p2remains;
	CStatic m_p2cards;
	CStatic m_p2name;
	int m_p2card;
	CStatic m_bell;
	CButton m_click;
	CStatic m_p1card;
	CStatic m_p1name;
	CStatic m_p1remains;
	CStatic m_p1cards;
	CButton m_press;
	afx_msg void OnBnClickedP1press();
	virtual void OnDraw(CDC* /*pDC*/);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	int m_view;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // HalliGalliView.cpp의 디버그 버전
inline CHalliGalliDoc* CHalliGalliView::GetDocument() const
   { return reinterpret_cast<CHalliGalliDoc*>(m_pDocument); }
#endif

