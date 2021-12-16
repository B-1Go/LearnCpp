#pragma once

class pCArr
{
private:
	int* m_pInt;
	int m_iCount;
	int m_iMax;

public:
	pCArr(); // 생성자 -> 객체 생성과 동시에 호출되는 함수 따라서 초기화 작업을 여기에 구현
	~pCArr(); // 소멸자 -> 객체 소멸과 동시에 호출되는 함수 따라서 동적할당(malloc) 메모리 해제는 여기에 구현

public:
	void push_back(int _iData);
	void resize(int _iResizeValue);
};