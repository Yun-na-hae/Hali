// Arrow.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HalliGalli_dlg.h"
#include "Arrow.h"
#include "afxdialogex.h"
#include "Arrow_piece.h"
#include "afxtempl.h"


// CArrow ��ȭ �����Դϴ�.

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


// CArrow �޽��� ó�����Դϴ�.


BOOL CArrow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	/*
	srand((unsigned int)time(NULL));
	m_arrowcnt = rand() % 4 + 5; //ȭ��ǥ ������ 5��~8������ �������� �����ϱ� ����
	for (int i = 0; i < m_arrowcnt; i++) {
		Arrow_piece* ap = new Arrow_piece();
		arrow_list.AddTail(ap);//ȭ��ǥ���� �迭�� �߰�
	}
	*/
	Arrow_piece* ap = new Arrow_piece();
	arrow_list.AddTail(ap);//ȭ��ǥ���� �迭�� �߰�
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}



void CArrow::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.

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
	
