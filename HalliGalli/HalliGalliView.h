
// HalliGalliView.h : CHalliGalliView Ŭ������ �������̽�
//

#pragma once
#include "afxwin.h"


class CHalliGalliView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CHalliGalliView();
	DECLARE_DYNCREATE(CHalliGalliView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_HALLIGALLI_FORM };
#endif

// Ư���Դϴ�.
public:
	CHalliGalliDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CHalliGalliView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // HalliGalliView.cpp�� ����� ����
inline CHalliGalliDoc* CHalliGalliView::GetDocument() const
   { return reinterpret_cast<CHalliGalliDoc*>(m_pDocument); }
#endif

