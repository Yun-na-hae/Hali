#pragma once


// CArrow ��ȭ �����Դϴ�.
#include "Arrow_piece.h"

class CArrow : public CDialogEx
{
	DECLARE_DYNAMIC(CArrow)

public:
	CArrow(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CArrow();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ARROW };
#endif
private:
	CList<Arrow_piece*> arrow_list;
	int m_arrowcnt;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
