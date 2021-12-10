#include <stdio.h>
#include <assert.h>
#include <iostream>

#include "Cstyle.h"

int main()
{
	tCArr arr = {};

	// �ʱ�ȭ
	InitalArr(&arr);

	Resize(&arr, 100);

	// ������ �ֱ�
	for (int i = 0; i < 10; ++i)
	{
		PushBack(&arr, i);
	}
	PushBack(&arr, 100);

	PushInsert(&arr, 3, 500);
	PushInsert(&arr, 100, 0);

	DeleteArr(&arr, 5);

	BubbleSort(&arr);

	// ������ ����ؼ� ����
	for (int i = 0; i < arr.iCount; ++i)
	{
		printf("%d\n", arr.pInt[i]);
	}

	// �޸� ����
	ReleaseArr(&arr);

	return 0;
}

// TODO
// 1. ���� �����ϱ�(�Ϸ�) -> �׽�Ʈ �غ���!

// 1. operater = ��� �Ϻ����� �غ���
// 2. operater[] ��� �Ϻ����� �غ���
// 3. arr�� �׳� �迭�� ������