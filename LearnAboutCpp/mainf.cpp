#include "Arrf.h"
#include <stdio.h>
#include <iostream>


int main()
{
	tArrf tf;

	// 초기화
	InitArrf(&tf);

	// 값 집어넣기
	for (int i = 0; i < 10; ++i)
	{
		float f = i + 0.1;
		PushBack(&tf, f);
	}

	for (int i = 0; i < tf.iCount; ++i)
	{
		printf("%f\n", tf.pfloat[i]);
	}

	// 메모리 해제
	ReleaseArrf(&tf);

	return 0;
}