#pragma once


// CArrow ��ȭ �����Դϴ�.

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

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
