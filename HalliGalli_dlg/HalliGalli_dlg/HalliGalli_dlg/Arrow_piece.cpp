#include "stdafx.h"
#include "Arrow_piece.h"


Arrow_piece::Arrow_piece()
{
	srand((unsigned int)time(NULL));
	m_direction = rand() % 4;//0¿Þ ,1¿À ,2À§,3¾Æ·¡
	switch (m_direction) {
	case 0 : m_arrow_img.Load(_T("./res/b_arrow_left.png"));
		break;
	case 1: m_arrow_img.Load(_T("./res/b_arrow_right.png"));
		break;
	case 2: m_arrow_img.Load(_T("./res/b_arrow_up.png"));
		break;
	case 3: m_arrow_img.Load(_T("./res/b_arrow_down.png"));
		break;
	}
}


Arrow_piece::~Arrow_piece()
{
}


CImage Arrow_piece::GetImage()
{
	return m_arrow_img;
}

int Arrow_piece::GetDirection()
{
	return m_direction;
}

void Arrow_piece::SetStatus(int status)
{
	// m_arrow_img.Load(); ·Î »ö±ò ¹Ù²ãÁÜ
}
