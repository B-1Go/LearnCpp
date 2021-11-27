#include <iostream>

#include "Arr.h"

int main()
{
	tArr s = {};
	InitArr(&s);

	for (int i = 0; i < 10; ++i)
	{
		PushBack(&s, i);
	}

	ReleaseArr(&s);

	// 연결형 리스트

	return 0;
}