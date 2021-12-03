#include <iostream>
#include <stdio.h>

#include <time.h>

#include "Arr.h"
#include "LinkedList.h"


void BubbleSort(int* _pData, int _iCount)
{
	// 1개 일때 예외 처리
	if (_iCount <= 1)
		return;

	while (true)
	{
		bool bFinish = true;

		// 오름차순
		int iLoop = _iCount - 1;
		for (int i = 0; i < iLoop; ++i)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = iTemp;

				bFinish = false;
			}
		}

		if (bFinish)
			break;
	}
}

// 함수포인터
void Test()
{

}


int main()
{
	// 함수의 주소를 받는 포인터
	void(*pFunc)(void) = nullptr;
	pFunc = Test;

	pFunc(); // Test함수를 호출한다는 뜻이다.

	int iArr[10] = { 87,644,21,55,879,654,50,131, };
	BubbleSort(iArr, 10);

	tArr s = {};
	InitArr(&s);

	// 난수(랜덤)
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

	sort(&s, &BubbleSort);
	printf("정렬후\n");
	for (int i = 0; i < s.iCount; ++i)
	{
		printf("%d\n", s.pInt[i]);
	}

	ReleaseArr(&s);

	return 0;
}

// 1. 가변배열
// 스스로 구현 가능하게 복습할 것

// 2. 정렬배열 안에 넣은 데이터 정렬
// - 버블 정렬