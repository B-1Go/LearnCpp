#include <stdio.h>


int main()
{
	int arr[5] = { 5, 3, 4, 1, 2 };

	// 배열 길이 구하기

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) // https://jhnyang.tistory.com/203
	{
		printf("%d\n", i);
	}

	int arrlen = sizeof(arr) / sizeof(arr[0]);

	// 버블 정렬(오름차순)
	for (int i = 0; i < arrlen - 1; ++i)
	{
		for (int i = 0; i < arrlen - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < arrlen; i++)
	{
		printf("%d\n", arr[i]);
	}


	return 0;
}