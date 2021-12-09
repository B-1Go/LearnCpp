#include <stdio.h>
#include <assert.h>
#include <iostream>

#include "Cstyle.h"

int main()
{
	tCArr arr = {};

	// 초기화
	InitalArr(&arr);

	// 데이터 넣기
	PushBack(&arr, 10);

	// 메모리 해제
	ReleaseArr(&arr);

	return 0;
}

// TODO
// 1. C스타일 배열 마무리 - Resize 만들기
// 2. Quest 구현해보기