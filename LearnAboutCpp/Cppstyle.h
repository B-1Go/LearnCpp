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
	void push_insert(int _idx, int _iData);
	void resize(int _iResizeValue);
	void show_data();
};

struct tabNode
{
	int iData;
	tabNode* pNextNode;
};

class pList
{
private:
	tabNode* m_pHeadNode;
	int m_iCount;

public:
	pList();
	~pList();

public:
	void push_back(int _iData);
	void psuh_insert(int _Idx, int _iData);
	void show_data();
};

