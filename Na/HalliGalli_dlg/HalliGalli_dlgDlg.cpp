
// HalliGalli_dlgDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "HalliGalli_dlg.h"
#include "HalliGalli_dlgDlg.h"
#include "Arrow.h"
#include "afxdialogex.h"
#include "Main.h"
#pragma comment(lib, "winmm")
#include <mmsystem.h>
#include "SpacebarDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHalliGalli_dlgDlg 대화 상자



CHalliGalli_dlgDlg::CHalliGalli_dlgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_HALLIGALLI_DLG_DIALOG, pParent)
	, sound(TRUE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHalliGalli_dlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
//	DDX_Control(pDX, IDC_EDIT1, m_p2_num);
//	DDX_Control(pDX, IDC_EDIT3, m_p1_num);
//	DDX_Control(pDX, IDC_EDIT2, m_all_num);
//	DDX_Control(pDX, IDC_P1_NUM, m_p1_nums);
	DDX_Control(pDX, IDC_P2_RE, m_p2_re);
	DDX_Control(pDX, IDC_ALL_RE, m_all_re);
	DDX_Control(pDX, IDC_P1_RE, m_p1_re);
}

BEGIN_MESSAGE_MAP(CHalliGalli_dlgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BELLRING, &CHalliGalli_dlgDlg::OnBnClickedButtonBellring)
	ON_BN_CLICKED(IDC_BUTTON_PRESS, &CHalliGalli_dlgDlg::OnBnClickedButtonPress)
	ON_WM_TIMER()
	ON_COMMAND(ID_HIGH, &CHalliGalli_dlgDlg::OnHigh)
	ON_UPDATE_COMMAND_UI(ID_HIGH, &CHalliGalli_dlgDlg::OnUpdateHigh)
	ON_COMMAND(ID_MIDDLE, &CHalliGalli_dlgDlg::OnMiddle)
	ON_UPDATE_COMMAND_UI(ID_MIDDLE, &CHalliGalli_dlgDlg::OnUpdateMiddle)
	ON_COMMAND(ID_LOW, &CHalliGalli_dlgDlg::OnLow)
	ON_UPDATE_COMMAND_UI(ID_LOW, &CHalliGalli_dlgDlg::OnUpdateLow)
	ON_COMMAND(ID_START_COM, &CHalliGalli_dlgDlg::OnStartCom)
	ON_COMMAND(ID_STOP, &CHalliGalli_dlgDlg::OnStop)
	ON_COMMAND(ID_END, &CHalliGalli_dlgDlg::OnEnd)
	ON_COMMAND(ID_HELP, &CHalliGalli_dlgDlg::OnHelp)
	ON_COMMAND(ID_SOUND, &CHalliGalli_dlgDlg::OnSound)
	ON_UPDATE_COMMAND_UI(ID_SOUND, &CHalliGalli_dlgDlg::OnUpdateSound)
END_MESSAGE_MAP()


// CHalliGalli_dlgDlg 메시지 처리기

BOOL CHalliGalli_dlgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_gamedata.Game_ready();

	show();
	
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CHalliGalli_dlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CHalliGalli_dlgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CHalliGalli_dlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHalliGalli_dlgDlg::OnBnClickedButtonBellring()
{
	time = FALSE;
	//SpacebarDlg Spacedlg;
	//Spacedlg.DoModal();

	if (bell_ring == TRUE)
	{
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		if (m_level == 0 || m_level == 1) {
			if(sound == TRUE)
				PlaySound(_T("./res/bell.wav"), NULL, SND_ASYNC);
			CArrow dlg;


			if (dlg.DoModal() == IDOK)
			{
				AfxMessageBox(_T("성공\nPlayer1 takes cards"));
				success = TRUE;
			}
			else {
				AfxMessageBox(_T("실패\nPlayer2 takes cards"));
				success = FALSE;
			}
		}
		else if (m_level == 2) {
			
			SpacebarDlg Spacedlg;
			if(sound == TRUE)
				PlaySound(_T("./res/bell.wav"), NULL, SND_ASYNC);


			if (Spacedlg.DoModal() == IDOK)
			{

				AfxMessageBox(_T("성공\nPlayer1 takes cards"));
				success = TRUE;
			}
			else {
				AfxMessageBox(_T("실패\nPlayer2 takes cards"));
				success = FALSE;
			}

			Success(success);

		}
	}
	else
	{
		AfxMessageBox(_T("This is not the time to ring the bell !"));
	}

	bell_ring = FALSE;
	CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON_PRESS);
	pBtn->EnableWindow(TRUE);

}


void CHalliGalli_dlgDlg::OnBnClickedButtonPress()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_gamedata.P1_cards.card_size() == 0 || m_gamedata.P2_cards.card_size() == 0)
	{
		if (m_gamedata.P1_cards.card_size() == 0)
			AfxMessageBox(_T("Player2 wins!!"));
		else if (m_gamedata.P2_cards.card_size() == 0)
			AfxMessageBox(_T("Player1 wins!!"));
		return;
	}

	bell_ring = FALSE;
	success = FALSE;
	time = TRUE;

	Card p1c = m_gamedata.P1_cards.get(0);
	Card p2c = m_gamedata.P2_cards.get(0);

	m_gamedata.Game_start();
	
	CImage p1c_image, p2c_image;

	CString strP1CardPath, strP2CardPath, tmp;

	tmp.Format(_T("./res/%c%d.png"), p1c.get_color(), p1c.get_number());
	strP1CardPath = tmp.MakeLower();

	tmp.Format(_T("./res/%c%d.png"), p2c.get_color(), p2c.get_number());
	strP2CardPath = tmp.MakeLower();
	
	CClientDC dc(this);
	p1c_image.Load(strP1CardPath);
	p1c_image.StretchBlt(dc.m_hDC, 725, 230, 150, 200, SRCCOPY);

	p2c_image.Load(strP2CardPath);
	p2c_image.StretchBlt(dc.m_hDC, 425, 230, 150, 200, SRCCOPY);

	show();


	if (m_gamedata.Compare(p1c, p2c)){
		bell_ring = TRUE;
		CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON_PRESS);
		pBtn->EnableWindow(FALSE);
		SetTimer(2000, 1500, NULL);
		
	}
	else
	{
		if (m_gamedata.P1_cards.card_size() == 0 || m_gamedata.P2_cards.card_size() == 0)
		{
			if(m_gamedata.P1_cards.card_size() == 0)
				AfxMessageBox(_T("Player2 wins!!"));
			else if(m_gamedata.P2_cards.card_size() == 0)
				AfxMessageBox(_T("Player1 wins!!"));
			return;
		}
	
	}
}


void CHalliGalli_dlgDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 2000) {
		KillTimer(2000);
		if (time == TRUE) {
			AfxMessageBox(_T("Player2 takes cards"));
			CButton* pBtn = (CButton*)GetDlgItem(IDC_BUTTON_PRESS);
			pBtn->EnableWindow(TRUE);
			while (m_gamedata.All_cards.card_size())
			{
				m_gamedata.P2_cards.push_card(m_gamedata.All_cards.get(0));
				m_gamedata.All_cards.pop_card();

				show();

			}
			bell_ring = FALSE;

			if (m_gamedata.P1_cards.card_size() == 0 || m_gamedata.P2_cards.card_size() == 0)
			{
				if (m_gamedata.P1_cards.card_size() == 0)
					AfxMessageBox(_T("Player2 wins!!"));
				else if (m_gamedata.P2_cards.card_size() == 0)
					AfxMessageBox(_T("Player1 wins!!"));
				return;
			}

		}
	}
	CDialogEx::OnTimer(nIDEvent);
}



void CHalliGalli_dlgDlg::OnHigh()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_level = 0;
}


void CHalliGalli_dlgDlg::OnUpdateHigh(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CMenu *hMenu = GetMenu();

	if (hMenu->GetMenuState(ID_HIGH, MF_BYCOMMAND) != MF_CHECKED) {
		hMenu->CheckMenuItem(ID_HIGH, MF_CHECKED);

		hMenu->CheckMenuItem(ID_MIDDLE, MF_UNCHECKED);
		hMenu->CheckMenuItem(ID_LOW, MF_UNCHECKED);

	}
	else {
		hMenu->CheckMenuItem(ID_HIGH, MF_UNCHECKED);
	}
}


void CHalliGalli_dlgDlg::OnMiddle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_level = 1;
}


void CHalliGalli_dlgDlg::OnUpdateMiddle(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CMenu *hMenu = GetMenu();

	if (hMenu->GetMenuState(ID_MIDDLE, MF_BYCOMMAND) != MF_CHECKED) {
		hMenu->CheckMenuItem(ID_MIDDLE, MF_CHECKED);

		hMenu->CheckMenuItem(ID_HIGH, MF_UNCHECKED);
		hMenu->CheckMenuItem(ID_LOW, MF_UNCHECKED);
	}
	else {
		hMenu->CheckMenuItem(ID_MIDDLE, MF_UNCHECKED);
	}
}


void CHalliGalli_dlgDlg::OnLow()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_level = 2;
}


void CHalliGalli_dlgDlg::OnUpdateLow(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CMenu *hMenu = GetMenu();

	if (hMenu->GetMenuState(ID_LOW, MF_BYCOMMAND) != MF_CHECKED) {
		hMenu->CheckMenuItem(ID_LOW, MF_CHECKED);

		hMenu->CheckMenuItem(ID_MIDDLE, MF_UNCHECKED);
		hMenu->CheckMenuItem(ID_HIGH, MF_UNCHECKED);
	}
	else {
		hMenu->CheckMenuItem(ID_LOW, MF_UNCHECKED);
	}
}


BOOL CHalliGalli_dlgDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN) {

		if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_SPACE) {
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CHalliGalli_dlgDlg::OnStartCom()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	while (m_gamedata.P1_cards.card_size())
	{
		m_gamedata.All_cards.push_card(m_gamedata.P1_cards.get(0));
		m_gamedata.P1_cards.pop_card();
	}

	while (m_gamedata.P2_cards.card_size())
	{
		m_gamedata.All_cards.push_card(m_gamedata.P2_cards.get(0));
		m_gamedata.P2_cards.pop_card();
	}


	m_gamedata.All_cards.shuffle(0, 55);

	//Player 1과 Player 2에게 28장씩 분배
	for (int i = 0; i < 28; i++)
	{
		m_gamedata.P1_cards.push_card(m_gamedata.All_cards.get(0));
		m_gamedata.All_cards.pop_card();
		m_gamedata.P2_cards.push_card(m_gamedata.All_cards.get(0));
		m_gamedata.All_cards.pop_card();
	}


	show();	
	
}


void CHalliGalli_dlgDlg::OnStop()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDialog dig(IDD_DIALOG1);

	if (dig.DoModal() == IDOK)
		return;
	else if (dig.DoModal() == IDCANCEL)
	{
		while (m_gamedata.P1_cards.card_size())
		{
			m_gamedata.All_cards.push_card(m_gamedata.P1_cards.get(0));
			m_gamedata.P1_cards.pop_card();
		}

		while (m_gamedata.P2_cards.card_size())
		{
			m_gamedata.All_cards.push_card(m_gamedata.P2_cards.get(0));
			m_gamedata.P2_cards.pop_card();
		}


		m_gamedata.All_cards.shuffle(0, 55);

		//Player 1과 Player 2에게 28장씩 분배
		for (int i = 0; i < 28; i++)
		{
			m_gamedata.P1_cards.push_card(m_gamedata.All_cards.get(0));
			m_gamedata.All_cards.pop_card();
			m_gamedata.P2_cards.push_card(m_gamedata.All_cards.get(0));
			m_gamedata.All_cards.pop_card();
		}


		show();	

		return;
	}
}


void CHalliGalli_dlgDlg::OnEnd()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	EndDialog(IDD_HALLIGALLI_DLG_DIALOG);
}


void CHalliGalli_dlgDlg::OnHelp()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDialog dig(IDD_HELP);

	dig.DoModal();

}


void CHalliGalli_dlgDlg::show()
{
	str_num.Format(_T("%d"), m_gamedata.All_cards.card_size());
	m_all_re.SetWindowText(str_num);
	str_num.Format(_T("%d"), m_gamedata.P1_cards.card_size());
	m_p1_re.SetWindowText(str_num);
	str_num.Format(_T("%d"), m_gamedata.P2_cards.card_size());
	m_p2_re.SetWindowText(str_num);

	CImage p1c_re_image, p2c_re_image;

	CString strP1CardREPath, strP2CardREPath, tmp;

	tmp.Format(_T("./res/p1_%d.png"), m_gamedata.P1_cards.card_size());
	strP1CardREPath = tmp.MakeLower();

	tmp.Format(_T("./res/p2_%d.png"), m_gamedata.P2_cards.card_size());
	strP2CardREPath = tmp.MakeLower();

	CClientDC dc(this);
	p1c_re_image.Load(strP1CardREPath);
	p1c_re_image.StretchBlt(dc.m_hDC, 800,550, 450, 150, SRCCOPY);

	p2c_re_image.Load(strP2CardREPath);
	p2c_re_image.StretchBlt(dc.m_hDC, 20, 40, 450, 150, SRCCOPY);
}


void CHalliGalli_dlgDlg::Success(bool success)
{

	if (success == TRUE) {
		while (m_gamedata.All_cards.card_size())
		{
			m_gamedata.P1_cards.push_card(m_gamedata.All_cards.get(0));
			m_gamedata.All_cards.pop_card();
			show();

		}
	}
	else if (success == FALSE)
	{
		while (m_gamedata.All_cards.card_size())
		{
			m_gamedata.P2_cards.push_card(m_gamedata.All_cards.get(0));
			m_gamedata.All_cards.pop_card();
			show();
		}
	}

	if (m_gamedata.P1_cards.card_size() == 0 || m_gamedata.P2_cards.card_size() == 0)
	{
		if (m_gamedata.P1_cards.card_size() == 0)
			AfxMessageBox(_T("Player2 wins!!"));
		else if (m_gamedata.P2_cards.card_size() == 0)
			AfxMessageBox(_T("Player1 wins!!"));
		return;
	}
}


void CHalliGalli_dlgDlg::OnSound()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (sound == TRUE)
		sound = FALSE;
	else
		sound = TRUE;
}


void CHalliGalli_dlgDlg::OnUpdateSound(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CMenu *hMenu = GetMenu();

	if (hMenu->GetMenuState(ID_SOUND, MF_BYCOMMAND) != MF_CHECKED) {
		hMenu->CheckMenuItem(ID_SOUND, MF_CHECKED);

	}
	else {
		hMenu->CheckMenuItem(ID_SOUND, MF_UNCHECKED);
	}
}
