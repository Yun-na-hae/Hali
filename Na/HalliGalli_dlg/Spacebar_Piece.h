#pragma once
class Spacebar_Piece
{
public:
	CString strImagePath;

	Spacebar_Piece();
	~Spacebar_Piece();

	void SetCorrectStatus();
	CImage GetImage();



private:
	CImage m_spacebar_img;
	int m_status = 0; // 0 �ʱ����, 1 correct �����̽��ٸ� ������ ��


public:
	void LoadSpaceBarImage();
	int GetSpaceBarStatus();
};

