#include <stdio.h>

int Add(int a, int b)
{
	return a + b;
}



//함수
int main()
{
	int Data = Add(100, 200);

	// 반복문
	// for()
	//for (/*반복자 초기화(여기는 한번만 실행됨)*/ ; /*반복문 조건 체크(참,거짓)*/ ; /*반복자 변경*/)
	//{

	//}

	// 0, 1, 2, 3
	for (int i = 0; i < 2; ++i)
	{

		if (i % 2 == 1)
		{
			continue;
		}

		printf("Output Test\n");

		//continue;
		// 이걸 만나면 아래 코드를 실행하지 않고 다음으로 넘어간다

		//break;
		// 이걸 만나면 for문을 나간다.
	}


	/*int i = 0;
	while (i<2)
	{
		printf("Output Test\n");
		++i;

		continue;

		break;
	}*/

	// while()

	return 0;
}