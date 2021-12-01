#include <iostream>
#include <stdio.h>

#include <time.h>

#include "Arr.h"
#include "LinkedList.h"

int main()
{
	tArr s = {};
	InitArr(&s);

	// 남수(랜덤)
	srand(time(nullptr));

	// 값 대입
	for (int i = 0; i < 10; ++i)
	{
		int iRand = rand() % 100 + 1;
		PushBack(&s, iRand);
	}

	printf("정렬전\n");
	for (int i = 0; i < s.iCount; ++i)
	{
		printf("%d\n", s.pInt[i]);
	}

	sort(&s);
	printf("정렬후\n");
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