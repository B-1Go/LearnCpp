#include <stdio.h>
#include <assert.h>
#include <iostream>

#include "Cstyle.h"
#include "Cppstyle.h"

int main()
{
	//// 가변배열 구현완료!
	//tCArr arr = {};

	//// 초기화
	//InitalArr(&arr);

	//Resize(&arr, 100);

	//// 데이터 넣기
	//for (int i = 0; i < 10; ++i)
	//{
	//	PushBackArr(&arr, i);
	//}
	//PushBackArr(&arr, 100);

	//PushInsertArr(&arr, 3, 500);
	//PushInsertArr(&arr, 100, 0);

	//DeleteArr(&arr, 5);

	//BubbleSort(&arr);

	//// 데이터 삽입 구현 테스트
	//tCArr arr2 = {};

	//// 초기화
	//InitalArr(&arr2);

	//PushBackArr(&arr2, 99);

	//// 데이터 넣기
	//for (int i = 20; i < 30; ++i)
	//{
	//	PushBackArr(&arr2, i);
	//}

	//// 머지구현 테스트
	//MergeArr(&arr, &arr2);

	//tCArr arr3 = {};
	//InitalArr(&arr3);
	//for (int i = 30; i < 40; ++i)
	//{
	//	PushBackArr(&arr3, i);
	//}
	//MergeArr(&arr, &arr3, 5);

	//// 메모리 해제
	//ReleaseArr(&arr);

	//---------------------------------------------------------------------------------------------------------------------------------------------------

	//// 연결형리스트 구현완료!
	//tList list = {};

	//InitalList(&list);

	//PushBackList(&list, 10);
	//PushBackList(&list, 20);
	//PushBackList(&list, 30);
	//PushInsertList(&list, 2, 25);

	//ReleaseList(&list);

	//---------------------------------------------------------------------------------------------------------------------------------------------------

	//// cpp스타일 가변배열 구현
	//pCArr carr;
	//carr.push_back(10);
	//carr.push_back(20);
	//carr.push_back(30);
	//carr.show_data();

	//carr.push_insert(1, 15);
	//carr.show_data();

	// cpp스타일 연결형 리스트 구현
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
// 1. 레퍼런스 주소 공부하기