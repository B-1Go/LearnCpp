#include <iostream>
#include <stdio.h>

#include <time.h>

#include "Arr.h"
#include "LinkedList.h"

int main()
{
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

	sort(&s);
	printf("������\n");
	for (int i = 0; i < s.iCount; ++i)
	{
		printf("%d\n", s.pInt[i]);
	}

	ReleaseArr(&s);

	// ������ ����Ʈ



	return 0;
}

// 1. �����迭
// ������ ���� �����ϰ� ������ ��

// 2. ���Ĺ迭 �ȿ� ���� ������ ����
// - ���� ����