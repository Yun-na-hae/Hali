
// HalliGalliView.cpp : CHalliGalliView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CHalliGalliView ����/�Ҹ�

CHalliGalliView::CHalliGalliView()
	: CFormView(IDD_HALLIGALLI_FORM)
	, m_p2card(0)
	, m_view(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CHalliGalliView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();


}


// CHalliGalliView ����

#ifdef _DEBUG
void CHalliGalliView::AssertValid() const
{
	CFormView::AssertValid();
}

void CHalliGalliView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CHalliGalliDoc* CHalliGalliView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHalliGalliDoc)));
	return (CHalliGalliDoc*)m_pDocument;
}
#endif //_DEBUG


// CHalliGalliView �޽��� ó����


void CHalliGalliView::OnStnClickedIdPreviewNext()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CHalliGalliView::OnStnClickedP2cards()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CHalliGalliView::OnBnClickedP1press()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	HBITMAP hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);

	m_p1card.SetBitmap(hBmp);

}


void CHalliGalliView::OnDraw(CDC* /*pDC*/)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	HBITMAP hBmp1 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP21), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);

	m_p1remains.SetBitmap(hBmp1);	//Player1�� �����ִ� ī���� ���(bitmap21)���

	HBITMAP hBmp2 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP22), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);

	m_p2remains.SetBitmap(hBmp2);	//Player2�� �����ִ� ī���� ���(bitmap22)���

	HBITMAP hBmp3 = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP23), IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS);

	m_bell.SetBitmap(hBmp3);	//�� ���(bitmap23)���

}



//void CHalliGalliView::OnSize(UINT nType, int cx, int cy)
//{
//	CFormView::OnSize(nType, cx, cy);
//
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
//
//
//}


void CHalliGalliView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}
