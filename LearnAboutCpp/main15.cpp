#include <iostream>

#include "Arr.h"
#include "CArr.h"

class CTest
{
private:
	int a;

public:
	CTest()
		: a(10)
	{

	}
};


//int Add(int a, int b)
//{
//	return a + b;
//}
//
//float Add(float f, float f1)
//{
//	return f + f1;
//}

template<typename T> // T 치환자료형
T Add(T a, T b)
{
	return a + b;
}



int main()
{
	// 구조체 --> 클래스

	// 객체지향 언어 특징
	// 1. 캡슐화
	// 기능을 수행하기 위해 필요한 멤버 선언, 묶음,	은닉성
	// 멤버 함수들

	// 2. 상속

	// 3. 다형성
	
	// 4. 추상화

	// 구조체 버전 가변배열 --> 클래스 버전

	// CTest t; // 생성자가 private 필드에 있으면 객체 생성이 안됨. 컴파일러가 자동으로 호출하는데 숨기면 호출을 못하기 때문이다.


	// C++ 동적할당 new, delete
	CTest* pTest = new CTest; // new가 malloc과 같은 역할을 한다.
	// malloc은 순순히 할당만 할 뿐 데이터를 어떻게 해석할지는 포인터에 캐스팅을 붙여서 선언했지만
	// class는 new + CTest를 함으로써 pTest에 어떻게 데이터를 해석할지 의미한다. 즉 int* pInt = (int*)malloc(4) -> int* pInt = new int 이런식으로 선언 할 수 있는 것이다.
	delete pTest;

	// tArr 예시
	tArr arr = {};
	InitArr(&arr);

	PushBack(&arr, 10);
	PushBack(&arr, 20);
	PushBack(&arr, 30);

	ReleaseArr(&arr);


	// 클래스 템플릿 -> 헤더에 구현해줘야 한다. 컴파일러가 main은 헤더에 선언된 함수로 문제 없이 컴파일이 되는데 구현한 cpp 파일은 치환자료형이 그대로 있기 때문에 문제가 됨.
	CArr<int> carr;
	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	int iData = carr[1];


	CArr<float> farr;
	farr.push_back(3.14f);
	farr.push_back(6.28f);
	farr.push_back(30.444f);

	float fData = farr[1];


	// 함수 템플릿
	int i = Add<int>(10, 20); // Add는 Add인데<T> 자리에 int가 들어간 자료형
	int i2 = Add(30, 40); // 함수처럼 생겼지만 이 경우에는 컴파일러가 치환자료형에 int를 넣어준 것 이다.
	Add<int>(100, 200); // Add가 함수냐? -> 아니다 함수 와 함수 템플릿은 엄연히 다르다

	return 0;
}