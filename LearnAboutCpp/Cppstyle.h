#pragma once

class pCArr
{
private:
	int* m_pInt;
	int m_iCount;
	int m_iMax;

public:
	pCArr(); // ������ -> ��ü ������ ���ÿ� ȣ��Ǵ� �Լ� ���� �ʱ�ȭ �۾��� ���⿡ ����
	~pCArr(); // �Ҹ��� -> ��ü �Ҹ�� ���ÿ� ȣ��Ǵ� �Լ� ���� �����Ҵ�(malloc) �޸� ������ ���⿡ ����

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

