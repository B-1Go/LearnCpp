#include <iostream>

// 변수
// 지역(스택)
// 전역, 정적, 외부(데이터)


// 메모리 영역
// 스택
// 데이터
// ROM
// 힙 영역(동적할당)

void Test(int a)
{
	printf("%d\n", a);
}


int main()
{
	int* pInt = (int*)malloc(100); // 100바이트를 힙에 할당하고 스택 메모리에 있는 pInt에 시작주소(포인터)를 넘겨준다.
	// malloc이 void 타입으로 주는 이유 : 순순히 할당 메모리만 줄뿐. 사용하고 싶은 자료형으로 정하면 된다.
	float* pF = (float*)malloc(4);

	// 동적할당
	// 1. 런타임 중에 대응 기능
	// 2. 사용자가 직접 메모리를 관리해야함(헤제)

	Test(10); // 컴파일러가 메모리 항당량을 알아서 해제해주고 있음

	int iInput = 0;
	scanf_s("%d", &iInput);

	int* pInt = nullptr;

	if (100 == iInput)
	{
		pInt = (int*)malloc(100);
	}

	if (nullptr != pInt)
	{
		free(pInt); // free는 힙메모리에 있는 동적할당을 해제해주는 함수이다.
		// 스택에 있는 pInt가 헤제되는게 아니라, 안에 할당된 malloc을 헤제해주는 함수이다.
	}

	return 0;
}