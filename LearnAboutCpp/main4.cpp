
# include <stdio.h>


// C스탈일 구조체
// 구조체란 사용자 정의 자료형라 할 수 있다.
typedef struct _tagMyST
{
	int a; // int a라고 해서 a가 변수처럼 보이는데 너가 정의한 [자료형]이기 때문에
	float f; // a는 int를 접근하는 이름이 되고, f는 float에 접근하는 자료형이 된다.
}MYST;

typedef struct _tagBig
{
	MYST k; // 작은 기본 자료형으 묶에서 더 큰 자료형으 만들 수 있다.
	int i;
	char c;
}BIG;

typedef int INT; // typedef 는 자료형을 아예 재정의 해주는 녀셕이다.


// C++은 이렇게 구조체를 선언하고 NewStruct라고 선언하여 사용할 수 있는데
// C에서는 기본자료형이 아닌 struct를 따로 관리하기 때문에 struct NewStruct라고 선언해야 사용 할 수 있다.
// C 또는 C++ 에서 범용적으로 사용 할 수 있게 typedef를 사용하여 정의하면 C에서도 사용 할 수 있다.
struct NewStruct
{
	int a;
	short s;
};

// 아래와 같이 NEWST로 자료형으 정의하면 C나 C++에서 다 사용가능하다.
typedef struct NewStruct
{
	int a;
	short s;
}NEWST;





int main()
{
	int arr[10] = { 1, 2, 3, 4, 5 }; // 초기화 처리 첫번째부터 순서대로 들어가며 빈 곳은 0이 들어간다.

	// 구조체
	MYST t = { 100, 3.14f }; // 구조체도 배열처럼 초기화 처리 및 초기값 대입이 가능하다. 따라서 int a = 100, float f = 3.14f 가 대입된다.
	t.a = 10; // t자료형에 세부적으로 접근하는 방법
	t.f = 10.314f;


	int iSize = sizeof(MYST);

	INT a; // typedef으로 기본자료형 int를 INT로 정의 해줬기 때문에 컴파일러가 int로 알아 듣는다.

	return 0;
};