#include <stdio.h>
#include <assert.h>
#include <iostream>

#include "Cstyle.h"
#include "Cppstyle.h"

int main()
{
	//// �����迭 �����Ϸ�!
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

	//// ����������Ʈ �����Ϸ�!
	//tList list = {};

	//InitalList(&list);

	//PushBackList(&list, 10);
	//PushBackList(&list, 20);
	//PushBackList(&list, 30);
	//PushInsertList(&list, 2, 25);

	//ReleaseList(&list);

	//---------------------------------------------------------------------------------------------------------------------------------------------------

	//// cpp��Ÿ�� �����迭 ����
	//pCArr carr;
	//carr.push_back(10);
	//carr.push_back(20);
	//carr.push_back(30);
	//carr.show_data();

	//carr.push_insert(1, 15);
	//carr.show_data();

	// cpp��Ÿ�� ������ ����Ʈ ����
	pList list;
	list.psuh_insert(0, 5);
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);
	list.psuh_insert(2, 15);
	list.psuh_insert(99, 40);


	return 0;
}

// TODO
// 1. ���۷��� �ּ� �����ϱ�