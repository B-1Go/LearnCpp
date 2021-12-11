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

	// ������ ���� ���� �׽�Ʈ
	tCArr arr2 = {};

	// �ʱ�ȭ
	InitalArr(&arr2);

	PushBack(&arr2, 99);

	// ������ �ֱ�
	for (int i = 20; i < 30; ++i)
	{
		PushBack(&arr2, i);
	}

	// �������� �׽�Ʈ
	MergeArr(&arr, &arr2);

	tCArr arr3 = {};
	InitalArr(&arr3);
	for (int i = 30; i < 40; ++i)
	{
		PushBack(&arr3, i);
	}
	MergeArr(&arr, &arr3, 5);

	// �޸� ����
	ReleaseArr(&arr);

	return 0;
}