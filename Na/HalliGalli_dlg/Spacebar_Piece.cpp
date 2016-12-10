#include "stdafx.h"
#include "Spacebar_Piece.h"


Spacebar_Piece::Spacebar_Piece()
{
	
}


Spacebar_Piece::~Spacebar_Piece()
{
	m_spacebar_img.Destroy();
}

void Spacebar_Piece::SetCorrectStatus()
{
	m_status = 1; // 맞게 눌렀으니까 스페이스바를 없애주어야 함
}

int Spacebar_Piece::GetSpaceBarStatus()
{
	return m_status;
}



CImage Spacebar_Piece::GetImage()
{
	return m_spacebar_img;
}

void Spacebar_Piece::LoadSpaceBarImage()
{
	m_spacebar_img.Destroy();

	if(m_status == 0) { //0노멀 1correct
	
			strImagePath = _T("./res/spacebar.png");
		
	}
	else if (m_status == 1) {//스페이스 바를 눌렀을 때
		strImagePath = _T("./res/spacebar_TransPa.png");

	}
	if (SUCCEEDED(m_spacebar_img.Load(strImagePath))) {
		if (m_spacebar_img.GetBPP() == 32)
		{
			unsigned char * pCol = 0;
			long w = m_spacebar_img.GetWidth();
			long h = m_spacebar_img.GetHeight();
			for (long y = 0; y < h; y++) {
				for (long x = 0; x < w; x++) {
					pCol = (unsigned char *)m_spacebar_img.GetPixelAddress(x, y);
					unsigned char alpha = pCol[3];
					if (alpha != 255) {
						pCol[0] = ((pCol[0] * alpha) + 128) >> 8;
						pCol[1] = ((pCol[1] * alpha) + 128) >> 8;
						pCol[2] = ((pCol[2] * alpha) + 128) >> 8;

					}
				}
			}
		}
		m_spacebar_img.SetHasAlphaChannel(true);
	}
}

