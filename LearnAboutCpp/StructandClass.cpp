#include <stdio.h>
#include <assert.h>
#include <iostream>

#include "Cstyle.h"

int main()
{
	//tCArr arr = {};

	//// �ʱ�ȭ
	//InitalArr(&arr);

	//Resize(&arr, 100);

	//// ������ �ֱ�
	//for (int i = 0; i < 10; ++i)
	//{
	//	PushBackArr(&arr, i);
	//}
	//PushBackArr(&arr, 100);

	//PushInsertArr(&arr, 3, 500);
	//PushInsertArr(&arr, 100, 0);

	//DeleteArr(&arr, 5);

	//BubbleSort(&arr);

	//// ������ ���� ���� �׽�Ʈ
	//tCArr arr2 = {};

	//// �ʱ�ȭ
	//InitalArr(&arr2);

	//PushBackArr(&arr2, 99);

	//// ������ �ֱ�
	//for (int i = 20; i < 30; ++i)
	//{
	//	PushBackArr(&arr2, i);
	//}

	//// �������� �׽�Ʈ
	//MergeArr(&arr, &arr2);

	//tCArr arr3 = {};
	//InitalArr(&arr3);
	//for (int i = 30; i < 40; ++i)
	//{
	//	PushBackArr(&arr3, i);
	//}
	//MergeArr(&arr, &arr3, 5);

	//// �޸� ����
	//ReleaseArr(&arr);

	//---------------------------------------------------------------------------------------------------------------------------------------------------

	tList list = {};

	InitalList(&list);

	PushBackList(&list, 10);
	PushBackList(&list, 20);
	PushBackList(&list, 30);
	PushInsertList(&list, 2, 25);

	ReleaseList(&list);

	return 0;
}

// TODO
// 1. ������ ����Ʈ C��Ÿ�Ϸ� �����ϱ�(�Ϸ�!)
// 2. ������ �ֹ��� ����Ʈ�� �����ϱ�