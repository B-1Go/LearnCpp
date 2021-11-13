#include <stdlib.h>
#include <stdio.h>

void Output(const int* pI)
{
	// 참고로 Int는 4바이트고 주소 변수는 x64운영체제에서는 8바이트라서 사실 복사하는게 더 코스트가 낮다
	// 하지만 데이터가 큰 구조체라고 생각하자ㅋㅋ
	int i = *pI;
	// *pI = 10;
	// 그렇다면 수정이 불가능 한거냐? 아니다
	// int* pInt = (int*)pI; // 일반 const 포인터를 일반 포인터로 강제 캐스팅해서 변경 가능하다.
	// *pInt = 1000;
	// const_cast // 라고 일반 포인터로 바꿔주는 기능도 지원한다.
}


int main()
{
	// const
	const int i = 100;

	// const와 포인터
	int a = 0;
	int* pInt = &a;

	*pInt = 1;
	pInt = nullptr;

	// const 포인터
	const int* pConstInt = &a; // 포인터로 접근하는 a 변수가 상수처럼 취급된다. 포인터의 기능을 제한하는 것이다.
	// *pConstInt = 100;

	int b = 0;
	pConstInt = &b;


	// 포인터 const 
	int* const pIntConst = &a; // pIntConst 포인터 변수가 상수화 됨
	*pIntConst = 100;
	// pIntConst = &b;

	// 초기화 시 가리킨 대상만 가리킴, 가리키는 원본을 수정 할 수 없음
	const int* const pConstIntConst = nullptr; // 2가지 동시에 응용가능


	// 이렇게 쓰는 사암은 거의 없는데 딱 1번 봤다는 강사
	int const* p = &a; // const가 *뒤에 있으므로 포인터로 접근하는 a변수가 상수처럼 취급된다. *은 해당 주소의 변수를 가르키므로 a 변수가 상수가 된다.
	//*p = 1;


	{
		// 주의사항!
		int a = 0;
		const int* pInt = &a; // const를 붙였다고 a변수 자체가 상수화가 되는 것은 아니다. 단지 포인터가 a주소 값을 변경할 때 상수처럼 취급되게 하게 만든 것이다.
		// 즉, 포인터의 입장에서 a변수가 const인 것이다.
		
		// *pInt = 100;
		a = 100; // 여기처럼 a 자체는 int a 이므로 수정이 가능하다.

		int* p = &a;
		*p = 100;
	}


	// 그러면 어떻게 사용이 될까?
	// 기본적으로 함수의 호출을 하면 자기 스택에 데이터를 복사하는 방식으로 동작된다.
	// 데이터가 무지막지하게 큰 구조체라면 성능이 저하는 될 것이다.
	// 그래서 호출되는 함수한테 주소를 넘겨주면 되지 않을까? 따라서 저런 방식의 접근이 생긴것이다.
	// 그런데 포인터로 접근하면 main에 있는 스택메모리 변수 a를 Output이 수정 할 수 있게 된다.
	// 따라서 const int* pI해서 참조는 하되 값을 변경 못하게 방지한다.

	a = 100;
	Output(&a);

	printf("%d\n", a);


	return 0;
}

// 단축키
// Ctrl + Shift + Space