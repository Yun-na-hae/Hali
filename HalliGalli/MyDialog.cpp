// MyDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HalliGalli.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// CMyDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_HALLIGALLI_FORM, pParent)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
//	ON_WM_SIZE()
END_MESSAGE_MAP()


// CMyDialog �޽��� ó�����Դϴ�.


//void CMyDialog::OnSize(UINT nType, int cx, int cy)
//{
//	CDialog::OnSize(nType, cx, cy);
//
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
//
//
//
//}
