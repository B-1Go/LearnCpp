#include <stdio.h>
#include <assert.h>
#include <iostream>

#include "Cstyle.h"

int main()
{
	tCArr arr = {};

	// 초기화
	InitalArr(&arr);

	Resize(&arr, 100);

	// 데이터 넣기
	for (int i = 0; i < 10; ++i)
	{
		PushBack(&arr, i);
	}
	PushBack(&arr, 100);

	PushInsert(&arr, 3, 500);
	PushInsert(&arr, 100, 0);

	DeleteArr(&arr, 5);

	BubbleSort(&arr);

	// 데이터 삽입 구현 테스트
	tCArr arr2 = {};

	// 초기화
	InitalArr(&arr2);

	PushBack(&arr2, 99);

	// 데이터 넣기
	for (int i = 20; i < 30; ++i)
	{
		PushBack(&arr2, i);
	}

	// 머지구현 테스트
	MergeArr(&arr, &arr2);

	tCArr arr3 = {};
	InitalArr(&arr3);
	for (int i = 30; i < 40; ++i)
	{
		PushBack(&arr3, i);
	}
	MergeArr(&arr, &arr3, 5);

	// 메모리 해제
	ReleaseArr(&arr);

	return 0;
}