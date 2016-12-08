#pragma once

#include "Spacebar_Piece.h"
#include "afxcmn.h"
#include "afxwin.h"
#include "HalliGalli_dlgDlg.h"

// SpacebarDlg 대화 상자입니다.

class SpacebarDlg : public CDialog
{
	DECLARE_DYNAMIC(SpacebarDlg)

public:
	SpacebarDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SpacebarDlg();
	

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPACE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.


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
