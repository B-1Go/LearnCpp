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
	void resize(int _iResizeValue);
};