#include <stdlib.h>
#include <stdio.h>

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



	return 0;
}