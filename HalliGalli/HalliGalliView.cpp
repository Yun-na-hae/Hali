
// HalliGalliView.cpp : CHalliGalliView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HalliGalli.h"
#endif

#include "HalliGalliDoc.h"
#include "HalliGalliView.h"
#include "afxwin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHalliGalliView

IMPLEMENT_DYNCREATE(CHalliGalliView, CFormView)

BEGIN_MESSAGE_MAP(CHalliGalliView, CFormView)
	ON_STN_CLICKED(AFX_ID_PREVIEW_NEXT, &CHalliGalliView::OnStnClickedIdPreviewNext)
	ON_STN_CLICKED(IDC_P2CARDS, &CHalliGalliView::OnStnClickedP2cards)
	ON_BN_CLICKED(IDC_P1PRESS, &CHalliGalliView::OnBnClickedP1press)
//	ON_WM_SIZE()
ON_WM_SIZE()
END_MESSAGE_MAP()

// CHalliGalliView 생성/소멸

CHalliGalliView::CHalliGalliView()
	: CFormView(IDD_HALLIGALLI_FORM)
	, m_p2card(0)
	, m_view(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CHalliGalliView::~CHalliGalliView()
{
}

void CHalliGalliView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_P2REMAINS, m_p2remains);
	DDX_Control(pDX, IDC_P2CARDS, m_p2cards);
	DDX_Control(pDX, IDC_P2NAME, m_p2name);
	DDX_Control(pDX, IDC_BELL, m_bell);
	DDX_Control(pDX, IDC_CLICK, m_click);
	DDX_Control(pDX, IDC_P1CARD, m_p1card);
	DDX_Control(pDX, IDC_P1NAME, m_p1name);
	DDX_Control(pDX, IDC_P1REMAINS, m_p1remains);
	DDX_Control(pDX, IDC_P1CARDS, m_p1cards);
	DDX_Control(pDX, IDC_P1PRESS, m_press);
}

BOOL CHalliGalliView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CHalliGalliView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();


}


// CHalliGalliView 진단

#ifdef _DEBUG
void CHalliGalliView::AssertValid() const
{
	CFormView::AssertValid();
}

void CHalliGalliView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CHalliGalliDoc* CHalliGalliView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHalliGalliDoc)));
	return (CHalliGalliDoc*)m_pDocument;
}
#endif //_DEBUG


// CHalliGalliView 메시지 처리기


void CHalliGalliView::OnStnClickedIdPreviewNext()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CHalliGalliView::OnStnClickedP2cards()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CHalliGalliView::OnBnClickedP1press()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	HBITMAP hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);

	m_p1card.SetBitmap(hBmp);

}


void CHalliGalliView::OnDraw(CDC* /*pDC*/)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	HBITMAP hBmp1 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP21), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);

	m_p1remains.SetBitmap(hBmp1);	//Player1의 남아있는 카드의 모양(bitmap21)출력

	HBITMAP hBmp2 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP22), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);

	m_p2remains.SetBitmap(hBmp2);	//Player2의 남아있는 카드의 모양(bitmap22)출력

	HBITMAP hBmp3 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP23), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);

	m_bell.SetBitmap(hBmp3);	//종 모양(bitmap23)출력

}



//void CHalliGalliView::OnSize(UINT nType, int cx, int cy)
//{
//	CFormView::OnSize(nType, cx, cy);
//
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//
//
//}


void CHalliGalliView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
