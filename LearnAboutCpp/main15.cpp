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


//int Add(int a, int b)
//{
//	return a + b;
//}
//
//float Add(float f, float f1)
//{
//	return f + f1;
//}

template<typename T> // T ġȯ�ڷ���
T Add(T a, T b)
{
	return a + b;
}



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


	// Ŭ���� ���ø� -> ����� ��������� �Ѵ�. �����Ϸ��� main�� ����� ����� �Լ��� ���� ���� �������� �Ǵµ� ������ cpp ������ ġȯ�ڷ����� �״�� �ֱ� ������ ������ ��.
	CArr<int> carr;
	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	int iData = carr[1];


	CArr<float> farr;
	farr.push_back(3.14f);
	farr.push_back(6.28f);
	farr.push_back(30.444f);

	float fData = farr[1];


	// �Լ� ���ø�
	int i = Add<int>(10, 20); // Add�� Add�ε�<T> �ڸ��� int�� �� �ڷ���
	int i2 = Add(30, 40); // �Լ�ó�� �������� �� ��쿡�� �����Ϸ��� ġȯ�ڷ����� int�� �־��� �� �̴�.
	Add<int>(100, 200); // Add�� �Լ���? -> �ƴϴ� �Լ� �� �Լ� ���ø��� ������ �ٸ���

	return 0;
}