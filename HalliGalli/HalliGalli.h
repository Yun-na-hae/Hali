
// HalliGalli.h : HalliGalli ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CHalliGalliApp:
// �� Ŭ������ ������ ���ؼ��� HalliGalli.cpp�� �����Ͻʽÿ�.
//

class CHalliGalliApp : public CWinApp
{
public:
	CHalliGalliApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHalliGalliApp theApp;
