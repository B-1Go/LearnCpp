#include <iostream>
#include <stdio.h>

#include <time.h>

#include "Arr.h"
#include "LinkedList.h"


void BubbleSort(int* _pData, int _iCount)
{
	// 1�� �϶� ���� ó��
	if (_iCount <= 1)
		return;

	while (true)
	{
		bool bFinish = true;

		// ��������
		int iLoop = _iCount - 1;
		for (int i = 0; i < iLoop; ++i)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = iTemp;

				bFinish = false;
			}
		}

		if (bFinish)
			break;
	}
}

// �Լ�������
void Test()
{

}


int main()
{
	// �Լ��� �ּҸ� �޴� ������
	void(*pFunc)(void) = nullptr;
	pFunc = Test;

	pFunc(); // Test�Լ��� ȣ���Ѵٴ� ���̴�.

	int iArr[10] = { 87,644,21,55,879,654,50,131, };
	BubbleSort(iArr, 10);

	tArr s = {};
	InitArr(&s);

	// ����(����)
	srand(time(nullptr));

	// �� ����
	for (int i = 0; i < 10; ++i)
	{
		int iRand = rand() % 100 + 1;
		PushBack(&s, iRand);
	}

	printf("������\n");
	for (int i = 0; i < s.iCount; ++i)
	{
		printf("%d\n", s.pInt[i]);
	}

	sort(&s, &BubbleSort);
	printf("������\n");
	for (int i = 0; i < s.iCount; ++i)
	{
		printf("%d\n", s.pInt[i]);
	}

	ReleaseArr(&s);

	return 0;
}

// 1. �����迭
// ������ ���� �����ϰ� ������ ��

// 2. ���Ĺ迭 �ȿ� ���� ������ ����
// - ���� ����