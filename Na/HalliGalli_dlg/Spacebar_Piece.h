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
	int m_status = 0; // 0 초기상태, 1 correct 스페이스바를 눌렀을 때


public:
	void LoadSpaceBarImage();
	int GetSpaceBarStatus();
};

