#pragma once

#include "Spacebar_Piece.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "HalliGalli_dlgDlg.h"

// SpacebarDlg ��ȭ �����Դϴ�.

class SpacebarDlg : public CDialog
{
	DECLARE_DYNAMIC(SpacebarDlg)

public:
	SpacebarDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SpacebarDlg();
	

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPACE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.


	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
private:
	CFont m_font;
	CFont m_font2;
	int m_spacebarcnt = 0;
	int temp_arr[20] = { 0, };
	CImage m_Spacebar_img;
	CString strImagePath;
	CRect m_rect;
	CString Str;
	int m_position = 0;
	CArray<Spacebar_Piece*> m_spacebar_arr;


public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	CProgressCtrl m_ProCtrl;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CStatic m_num;
};
