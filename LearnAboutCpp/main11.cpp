#include <iostream>

// 변수
// 지역(스택)
// 전역, 정적, 외부(데이터)


// 메모리 영역
// 스택
// 데이터
// ROM
// 힙 영역(동적할당)

int main()
{
	int* pInt = (int*)malloc(100); // 100바이트를 힙에 할당하고 스택 메모리에 있는 pInt에 시작주소(포인터)를 넘겨준다.
	// malloc이 void 타입으로 주는 이유 : 순순히 할당 메모리만 줄뿐. 사용하고 싶은 자료형으로 정하면 된다.
	float* pF = (float*)malloc(4);



	return 0;
}