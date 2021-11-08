
# include <stdio.h>

// 변수의 종류
// 1. 지역변수
// 2. 전역변수
// 3. 정적변수(static)
// 4. 외부변수(extern)

// 메모리 영역
// 1. 스택 영역
// 2. 데이터 영역
// 3. 읽기 전용(코드, ROM)
// 4. 힙 영역


// 전역함수
int g_i = 0; // Data 영역

// Data 영역 특징
// 프로그램 시작 시 생성
// 프로그램 종료 시 해제

#include "func.h"
#include "common.h"

// 정적 변수
// 자신의 파일에 고정되어 선언되므로 전역으로 쓰여도 나중에 무슨무슨파일 정적변수다 라고 알 수 있다.
// 따라서 작은 변수명이여도 해당 파일의 static 변수임을 표시하므로 func.cpp static int i 와 main7.cpp static int i 는 서로 다른 변수 인 것이다.
// 헷갈리면 c/c++ 26강 참조
// static int g_iStatic = 0;

// 그러면 함수 안에 선언하면 무슨일이 있을까?
int Test()
{
	static int i = 0;

	// int a = 0;
	
	++i;

	return i;
}
// 결론적으로 int a는 스택 메모리에 동작하므로 함수가 종료되면 데이터를 잃어버린다.
// 반면 static 메모리는 역시 Test()함수에서만 사용이 가능하지만 Data영역에서 동작하므로
// Test()함수가 매번 작동할때 데이터를 잃어버리지 않고 동작할 수 있다.
// 이 차이점이 가장 중요한 것 같다.
// 그럼 전역변수랑 차이가 뭐냐?
// 데이터를 함부로 접근못하게 제한하는 역할을 한다. 저 Test()라는 함수로만 static int i 를 접근하게 해주면서 Data영역에 저장하므로 함수가 종료되도 메모리가 날아가지 않는다.
// static int i = 0; 하면 계속 0이 대입되는거 아닌가요?
// C++에서는 한번 초기값을 주면 다음 2번째 동작하는 함수에서는 저 구문을 건너뛰고 코드가 실행된다. 이는 컴파일러가 알아서 처리해준다.


int main()
{
	g_iStatic = 100;
	g_iExtern = 500;

	Test();
	Test();
	Test();
	Test();
	int iCall = Test();
	printf("Test함수 호출 횟수 : %d\n", iCall);

	return 0;
}