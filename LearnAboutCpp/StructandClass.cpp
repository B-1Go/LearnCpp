#include <stdio.h>
#include <assert.h>
#include <iostream>

#include "Cstyle.h"

int main()
{
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
// 1. 연결형 리스트 C스타일로 구현하기(완료!)
// 2. 연결형 쌍방향 리스트도 구현하기