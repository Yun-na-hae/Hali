
// HalliGalli_dlgDlg.h : ��� ����
//

#pragma once
#include "Main.h"
#include "afxwin.h"

// CHalliGalli_dlgDlg ��ȭ ����
class CHalliGalli_dlgDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CHalliGalli_dlgDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	int m_level = 2;//0�� 1�� 2��

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HALLIGALLI_DLG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

public:
	Main m_gamedata;
	bool bell_ring;
	bool success;
	bool time;
	CString str_num;
	bool sound;

// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBellring();
	afx_msg void OnBnClickedButtonPress();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	CStatic m_p2_re;
	CStatic m_all_re;
	CStatic m_p1_re;
	afx_msg void OnHigh();
	afx_msg void OnUpdateHigh(CCmdUI *pCmdUI);
	afx_msg void OnMiddle();
	afx_msg void OnUpdateMiddle(CCmdUI *pCmdUI);
	afx_msg void OnLow();
	afx_msg void OnUpdateLow(CCmdUI *pCmdUI);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnStartCom();
	afx_msg void OnStop();
	afx_msg void OnEnd();
	afx_msg void OnHelp();
	void show();
	void Success(bool success);
	afx_msg void OnSound();
	afx_msg void OnUpdateSound(CCmdUI *pCmdUI);
};
