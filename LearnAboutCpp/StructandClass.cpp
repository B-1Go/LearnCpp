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

	// 데이터 출력해서 보기
	for (int i = 0; i < arr.iCount; ++i)
	{
		printf("%d\n", arr.pInt[i]);
	}

	// 메모리 해제
	ReleaseArr(&arr);

	return 0;
}

// TODO
// 1. 머지 구현하기(완료) -> 테스트 해보기!

// 1. operater = 기능 완벽구현 해보기
// 2. operater[] 기능 완벽구현 해보기
// 3. arr을 그냥 배열로 만들어보기