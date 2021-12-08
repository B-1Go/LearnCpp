#pragma once
class CArr
{
private:
	int* m_pInt;
	int m_iCount;
	int m_iMaxCount;

public:
	void push_back(int _Data);
	void resize(int _iResizeCount);


	int& operator[] (int idx);

public:
	// 持失切
	CArr();
	// 社瑚切
	~CArr();
};

