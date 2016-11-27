// Arrow.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HalliGalli_dlg.h"
#include "Arrow.h"
#include "afxdialogex.h"


// CArrow 대화 상자입니다.

IMPLEMENT_DYNAMIC(CArrow, CDialogEx)

CArrow::CArrow(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_ARROW, pParent)
{

}

CArrow::~CArrow()
{
}

void CArrow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CArrow, CDialogEx)
END_MESSAGE_MAP()


// CArrow 메시지 처리기입니다.
