// SpacebarDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HalliGalli_dlg.h"
#include "SpacebarDlg.h"
#include "afxdialogex.h"
#pragma comment(lib, "winmm")
#include <mmsystem.h>
#include "Spacebar_Piece.h"


// SpacebarDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(SpacebarDlg, CDialog)

SpacebarDlg::SpacebarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_SPACE, pParent)
{

	
}

SpacebarDlg::~SpacebarDlg()
{
}

void SpacebarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ProCtrl);
	DDX_Control(pDX, IDC_NUM, m_num);
}


BEGIN_MESSAGE_MAP(SpacebarDlg, CDialog)
	ON_WM_PAINT()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &SpacebarDlg::OnNMCustomdrawProgress1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// SpacebarDlg �޽��� ó�����Դϴ�.


BOOL SpacebarDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	
	m_font.CreateFont(110, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, 0);
	//m_num.SetFont(&m_font, TRUE);
	m_font2.CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, 0);

	GetDlgItem(IDC_NUM)->SetFont(&m_font);
	GetDlgItem(IDC_NOTICE)->SetFont(&m_font2);
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	int temp, index_size = 12 - 1, n;
	int i = 0;

	// �ӽ� �迭 �ʱ�ȭ
	for (i = 0; i < 12; i++)
	{
		temp_arr[i] = i;
	}
	// rand()��� �ߺ����� �ʰ� �����
	for (i = 0; i < 12; i++)
	{
		n = rand() % (index_size + 1);

		// ������ index�� ���� index swap�ϱ�
		temp = temp_arr[n];
		temp_arr[n] = temp_arr[index_size];
		temp_arr[index_size] = temp;
	}

	srand((unsigned int)time(NULL));
	m_spacebarcnt = rand() % 4 + 7; //7~10���� �����̽��� ���� ����
	for (int i = 0; i < m_spacebarcnt; i++) {
		Spacebar_Piece* sb = new Spacebar_Piece();
		m_spacebar_arr.Add(sb);//�����̽��ٵ��� �迭�� �߰�
	}

	m_ProCtrl.SetRange(0, 100);
	m_ProCtrl.SetPos(100);
	m_ProCtrl.SetStep(-2);
	SetTimer(1000, 100, NULL);//40�и������帶�� ��Ÿ�� �Լ� ����

	Str.Format(_T("%d"), m_spacebarcnt);
	m_num.SetWindowText(Str);



	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void SpacebarDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	this->GetClientRect(m_rect);
	//1161,706
	
	int max_x = m_rect.right ;//748  976  �����̽� �̹����� �߸��� �ʰ� �ϱ����� �ƽ��� ����
	int bottom = m_rect.bottom;
	int max_y = bottom - 130;//393   546

	//�����̽��� ������ŭ �������� �ߺ����� �ʰ� �����Ͽ� temp_arr�迭�� ����

	int xx = 0;

	for (int j = 0; j < m_spacebar_arr.GetCount(); j++)//�����̽��ٸ� �����س��� �迭�� ������ŭ ������ ����
	{
		Spacebar_Piece* sb = m_spacebar_arr.GetAt(j);
		sb->LoadSpaceBarImage();
		//ap->GetImage().TransparentBlt(dc.m_hDC, x + i * 100, 200, 100, 100, RGB(0, 0, 0));
		//ap->GetImage().BitBlt(dc.m_hDC, x + i * 100, 200,SRCCOPY);

	//for (int j = 0; j < m_spacebarcnt; j++) {//7��~10��
		
		// 0~11  , 12���� �������� Ŭ���̾�Ʈ�� ����
		switch (temp_arr[j]) {
		case 0: //x 0~187,   y 0~131 
			sb->GetImage().TransparentBlt(dc.m_hDC, rand() % (max_x/4-185) + xx,                               rand() % (max_y/3-90), 185, 90, RGB(89, 89, 89));
			break;
		case 1://x 188~ 374,   y 0~131 
			sb->GetImage().TransparentBlt(dc.m_hDC, rand() % (max_x / 4 - 185) + (max_x /4) + xx,           rand() % (max_y / 3 - 90), 185, 90, RGB(89, 89, 89));
			break;
		case 2://x 375~561,   y 0~131 
			sb->GetImage().TransparentBlt(dc.m_hDC, rand() % (max_x / 4 - 185) + (max_x / 4 * 2) + xx,     rand() % (max_y / 3 - 90), 185, 90, RGB(89, 89, 89));
			break;
		case 3://x 562~748,   y 0~131 
			sb->GetImage().TransparentBlt(dc.m_hDC, rand() % (max_x / 4 - 185) + (max_x / 4 * 3) + xx,     rand() % (max_y / 3 - 90), 185, 90, RGB(89, 89, 89));
			break;


		case 4://x 0~187,   y 132~262
			sb->GetImage().TransparentBlt(dc.m_hDC, rand() % (max_x / 4 - 185) + xx   ,                   rand() % (max_y / 3 - 90) + (max_y/3) , 185, 90, RGB(89, 89, 89));
			break;
		case 5://x 188~ 374,  y 132~262
			sb->GetImage().TransparentBlt(dc.m_hDC, rand() % (max_x / 4 - 185) + (max_x / 4) + xx,       rand() % (max_y / 3 - 90) + (max_y / 3), 185, 90, RGB(89, 89, 89));
			break;
		case 6://x 375~561,  y 132~262
			sb->GetImage().TransparentBlt(dc.m_hDC, rand() % (max_x / 4 - 185) + (max_x / 4 * 2) + xx,   rand() % (max_y / 3 - 90) + (max_y / 3), 185, 90, RGB(89, 89, 89));
			break;
		case 7://x 562~748,  y 132~262
			sb->GetImage().TransparentBlt(dc.m_hDC, rand() % (max_x / 4 - 185) + (max_x / 4 * 3) + xx,  rand() % (max_y / 3 - 90) + (max_y / 3), 185 , 90, RGB(89, 89, 89));
			break;


		case 8://x 0~187,   y 263 ~ 393
			sb->GetImage().TransparentBlt(dc.m_hDC, rand() % (max_x / 4 - 185) + xx ,                            rand() % (max_y / 3 - 90) + (max_y / 3 * 2), 185, 90, RGB(89, 89, 89));
			break;
		case 9://x 188~ 374,  y 263 ~ 393
			sb->GetImage().TransparentBlt(dc.m_hDC, rand() % (max_x / 4 - 185) + (max_x / 4) + xx,        rand() % (max_y / 3 - 90) + (max_y / 3 * 2), 185, 90, RGB(89, 89, 89));
			break;
		case 10://x 375~561,   y 263 ~ 393
			sb->GetImage().TransparentBlt(dc.m_hDC, rand() % (max_x / 4 - 185) + (max_x / 4 * 2) + xx,    rand() % (max_y / 3 - 90) + (max_y / 3 * 2), 185, 90, RGB(89, 89, 89));
			break;
		case 11://x 562~748,   y 263 ~ 393
			sb->GetImage().TransparentBlt(dc.m_hDC, rand() % (max_x / 4 - 185) + (max_x / 4 * 3) + xx,    rand() % (max_y / 3 - 90) + (max_y / 3 * 2), 185, 90, RGB(89, 89, 89));
			break;
		}
	}

	if (m_position == m_spacebar_arr.GetCount()) {
		KillTimer(1000);
		AfxMessageBox(_T("SUCCESS"));
		OnOK();
	}




}



BOOL SpacebarDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN) {
		Spacebar_Piece* sb = m_spacebar_arr.GetAt(m_position);

			if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE) {
				return TRUE;
			}

		//	for (int i = 0; i < m_spacebarcnt; i++) 
				if (pMsg->wParam == VK_SPACE) {
				//	int push_space = 1;
					PlaySound(_T("./res/correct.wav"), NULL, SND_ASYNC);

					Str.Format(_T("%d"), m_spacebarcnt - m_position - 1);
					m_num.SetWindowText(Str);
					sb->SetCorrectStatus();
				}
				else if (pMsg->wParam != VK_SPACE) {

					PlaySound(_T("./res/wrong.wav"), NULL, SND_ASYNC);
					OnCancel();
				}
			

		m_position++;
		if (m_position == m_spacebarcnt ) {
			OnOK();
		}
		Invalidate();
		
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void SpacebarDlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�

	*pResult = 0;
}


void SpacebarDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDEvent == 1000) {
		m_ProCtrl.StepIt();//������ -��ŭ �پ��
		if (m_ProCtrl.GetPos() == 0) {
			KillTimer(1000);
			PlaySound(_T("./res/wrong.wav"), NULL, SND_ASYNC);
			MessageBox(_T("�ð��ʰ� ��������"));
			OnCancel();
		}
	}

	CDialog::OnTimer(nIDEvent);
}
