#include <stdlib.h>
#include <stdio.h>

void Test(int* a)
{
	*a = 500;
}


int main()
{
	// 포인터 변수
	// 자료형 변수명
	int* pInt = nullptr;

	// 주소를 저장
	
	char* pChar = nullptr;
	short* pShort = nullptr;

	// 포인터 변수는 운영체제 비트에 따라 가변적이다. 64비트(8바이트) OS에서는 8바이트 포인터 변수가 된다.
	int iSize = sizeof(int*);

	int i = 0;
	pInt = &i;

	// 주소는 1바이트씩 부여된다.
	// 만약 pInt가 100번지라고 하면 4바이트 이므로 끝은 104번지가 된다.

	pInt += 1;
	// 포인터 변수의 +1은 단순히 100 + 1 = 101 이 되는게 아니라
	// 포인터 변수가 의미하는 크기에 다음 번지를 의미한다.
	// 따라서 pInt에 +1을 하면 104번지 즉, 4바이트씩 증가하게 된다.
	// 만약 char에 +1을 하면 1바이트씩, long long에 하면 8바이트씩 증가 한다.
	// 따라서 포인터 변수 증감은 그 자료형 크기에 따라서 왔다 갔다 한다.

	// pInt 는 int* 변수 이기 때문에, 가리키는 곳은 int로 해석한다.
	// 따라서 주소값을 1 증가하는 의미는 다음 int 위치로 접근하기 위해서 sizeof(int) 단위로	증가하게 된다.

	// 포인터와 배열
	// 배열의 특징
	// 1. 메모리가 연속적인 구조이다.
	// 2. 배열의 이름은 배열의 시작 주소이다.
	int iArr[10] = {};

	// int 단위로 접근 *(포인터변수명)
	*(iArr) = 10; // int[0] = 10;
	*(iArr + 1) = 10; // int[1] = 10;

	// int(&iArr2)[10] = iArr; 인트 배열 포인터가 정확한 표현인데 나중에 설명



	// 포인터 이해 확인 문제
	// 문제 1.
	short sArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int* pI = (int*)sArr;

	int iData = *((short*)(pI + 2));

	printf("1번 문제 정답 : %d\n", iData); // 5


	// 문제 2.
	char cArr[2] = { 1, 1 };
	
	short* pS = (short*)cArr;

	iData = *pS;

	printf("2번 문제 정답 : %d\n", iData); // 257


	int a = 100;

	Test(&a);

	printf("출력 : %d\n", a);
	// Test함수 안에 a = 500; 넣어도 main함수에 a는 바뀌지 않는다. 왜냐면 스택함수에 지역변수는 스택호출되고 사라지면 끝이기 때문이다.
	// 그러면 스택 메모리에 주소를 받아서 수정하면 되지 않을까?
	// 그래서 Test 함수로 main함수의 a변수의 주소를 받아서 수정하는 방법이 있다.

	scanf_s("%d", &a);
	// scanf_s가 왜 &a를 해야되는지 이제 이해할 수 있다.
	// 입력값의 주소를 넘겨줘서 주소의 데이터를 참조하여 변경하는 것이다.



	// const

	volatile const int cint = 100; // volatile(휘발성) : 레지스터 최적화 하지말고 cint 메모리 주소로 가서 value를 직접확인해라.

	// 상수화
	// r-value : 상수
	// l-value : 변수
	int ii = 10;
	// =기준으로 왼쪽은 left-value, 오른쪽은 right-value여서 위와 같다.

	pInt = (int*)&cint; // 상수화가 됬다고 못바꾸는건 아니고 C++에서 문법적으로 막아주는 것 뿐이다.
	*pInt = 300;
	printf("cint 출력 : %d\n", cint);




	return 0;
}