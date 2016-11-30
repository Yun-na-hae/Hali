#pragma once
class Arrow_piece
{
public:
	Arrow_piece();
	~Arrow_piece();

	CImage GetImage();
	int GetDirection();
	void SetStatus(int status);

private:
	CImage m_arrow_img;
	int m_direction;

};

