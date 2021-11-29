#include <iostream>
#include <stdio.h>
#include "Arr.h"
#include "LinkedList.h"

int main()
{
	tArr s = {};
	InitArr(&s);

	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s, i);
	}

	for (int i = 0; i < s.iCount; ++i)
	{
		printf("%d\n", s.pInt[i]);
	}

	ReleaseArr(&s);

	// 연결형 리스트



	return 0;
}

// 1. 가변배열
// 스스로 구현 가능하게 복습할 것

// 2. 정렬배열 안에 넣은 데이터 정렬
// - 버블 정렬