#include <iostream>

#include "Arr.h"
#include "CArr.h"

class CTest
{
private:
	int a;

public:
	CTest()
		: a(10)
	{

	}
};

int main()
{
	// ����ü --> Ŭ����

	// ��ü���� ��� Ư¡
	// 1. ĸ��ȭ
	// ����� �����ϱ� ���� �ʿ��� ��� ����, ����,	���м�
	// ��� �Լ���

	// 2. ���

	// 3. ������
	
	// 4. �߻�ȭ

	// ����ü ���� �����迭 --> Ŭ���� ����

	// CTest t; // �����ڰ� private �ʵ忡 ������ ��ü ������ �ȵ�. �����Ϸ��� �ڵ����� ȣ���ϴµ� ����� ȣ���� ���ϱ� �����̴�.


	// C++ �����Ҵ� new, delete
	CTest* pTest = new CTest; // new�� malloc�� ���� ������ �Ѵ�.
	// malloc�� ������ �Ҵ縸 �� �� �����͸� ��� �ؼ������� �����Ϳ� ĳ������ �ٿ��� ����������
	// class�� new + CTest�� �����ν� pTest�� ��� �����͸� �ؼ����� �ǹ��Ѵ�. �� int* pInt = (int*)malloc(4) -> int* pInt = new int �̷������� ���� �� �� �ִ� ���̴�.
	delete pTest;

	// tArr ����
	tArr arr = {};
	InitArr(&arr);

	PushBack(&arr, 10);
	PushBack(&arr, 20);
	PushBack(&arr, 30);

	ReleaseArr(&arr);

	// CArr ����
	CArr carr;
	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	// ���۷����� ��¥ �迭ó�� �����ߴµ� ���۷����� �����͸� ���� ���� �ؾ��Ѵ�.
	int iData = carr[1];
	carr[1] = 100;

	return 0;
}