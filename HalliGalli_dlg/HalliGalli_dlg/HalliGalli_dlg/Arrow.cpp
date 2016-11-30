// Arrow.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HalliGalli_dlg.h"
#include "Arrow.h"
#include "afxdialogex.h"
#include "Arrow_piece.h"
#include "afxtempl.h"


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
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CArrow 메시지 처리기입니다.


BOOL CArrow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	/*
	srand((unsigned int)time(NULL));
	m_arrowcnt = rand() % 4 + 5; //화살표 개수를 5개~8개까지 랜덤으로 생성하기 위함
	for (int i = 0; i < m_arrowcnt; i++) {
		Arrow_piece* ap = new Arrow_piece();
		arrow_list.AddTail(ap);//화살표들을 배열에 추가
	}
	*/
	Arrow_piece* ap = new Arrow_piece();
	arrow_list.AddTail(ap);//화살표들을 배열에 추가
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



void CArrow::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	/*
		POSITION  p = arrow_list.GetHeadPosition();
		for (p; p != arrow_list.GetTailPosition; p++) {
		arrow_list.GetHead().BitBlt(dc.m_hDC, 10, 10, SRCCOPY);

		*/
	Arrow_piece * ap;

	ap = arrow_list.GetHead();
	//*ap.BitBlt(dc.m_hDC, 10, 10, SRCCOPY);
	/*	for (int i = 0; i < m_arrowcnt; i++) {
	
			
			.BitBlt(dc.m_hDC, 10, 10, SRCCOPY);
		}*/

	}
	
