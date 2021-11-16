#include <stdlib.h>
#include <stdio.h>


// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(코드)



void Output(const int* pI) // void 없다라고 해석 할 수 있는데, return 되는 값이 없는 것이다. 만약 int거나 다른 자료형이라면 return 구문을 만나야 된다.
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


	// void
	// 1. 원본의 자료형을 정하지 않음
	// 2. 어떠한 타입의 변수의 주소든 다 저장 가능
	// 3. 역참조 불가능
	// 4. 주소 연산 불가능
	void* pVoid = nullptr; // void* 보이드포인터는 그 메모리 주소로 갔을때 어떻게 볼지 정해지지 않은 것이다. 따라서 어떤 데이터는 다 받을 수 있다.
	float* pFloat = nullptr;

	{
		int a = 0;
		float f = 0.f;
		double d = 0.;
		long long ll = 0;

		pVoid = &a;
		pVoid = &f;
		pVoid = &d;
		pVoid = &ll; // 아무 자료형이 다 받을 수 있지만

		// *pVoid; // 그 메모리 주소로 갔을 때 어떻게 해석 할지 정해진것이 없어서 역참조가 안된다.
		// pVoid + 1; // 당연히 주소 연산도 안된다.
	}

	{
		// 문자
		// char(1), wchar(2)
		char c = 1; // 1바이트 정수형 문자에 특화됨
		bool b = 1; // 1바이트 정수형

		wchar_t wc = 49; // 2바이트 정숭형 아스키코드 참고
		short s = 49; // 2바이트

		c = 1;
		c = '1';
		// 단일문자 '1'과 데이터 1은 다르다.

		wc = 459;
		"459";
		// 문자열은 ""로 표현하고, 문자열이 끝나는 마지막 메모리를 알려주기 위해서 마지막 다음은 0(NULL)이 들어간다.


		int i = 0;
	}

	{
		// 문자열
		// char(1) 실제로 사용하는 인덱스 갯수는 0~127이다.
		// wchar(2)

		char c = 'a';
		wchar_t wc = L'a'; // 2바이트로 사용하겠다 라고 명시하기 위해 L'a'; 표현한다.

		char szChar[10] = "abcdef"; // 이런 형태의 배열 초기화는 문자 자료형만 가능하다.
		wchar_t szWChar[10] = L"abcdef"; // 문자열에서 문자 하나하나가 2바이트로 구성되있다는 걸 알여주기 위해서 L"abcdef"; 로 표현하다. //문자열 끝에는 항상 보이지 않는 0, 즉 NULL이 들어있기 때문에 abcdef라고 해서 크기를 6으로 만들면 컴파일 에러가 난다. 7개 되어야 한다. 넉넉잡아 10을 넣음
		const wchar_t* pChar = L"abcdef"; // 문자들의 정체는 사실 주소값이 였다!! 이러한 특정 코드는 들은 ROM(코드)라고 따로 관리가 되고 있다.

		szWChar[1] = 'z';
		// pChar[1] = 'z'; -> *(pChar + 1) = 'z'; // 이 코드는 ROM(코드)를 프로그램이 실행중에 실시간으로 변경한다는 것인데 그러면 문제니까 const가 붙는다.

		szWChar[0];
		// pChar[0] = 'z'; // 문자열은 애초에 const 타입으로 반환 해준다. 과거 컴파일은 일반 주소를 넘겨줘서 문제가 많이 발생할 여지가 있었다. 컴파일러가 계속 개선 되고 있다.

		short arrShort[10] = { 97,98,99,100,101,102 };

		int a = 0;
	}



	return 0;
}