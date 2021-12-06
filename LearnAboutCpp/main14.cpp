#include <iostream>

#include "Arr.h"

struct tMy
{
	// tMy는 사용자가 정의한 자료형이다.]
	// ]
	// C++ 에서는 typedef 할 필요가 없다
};


class CMy
{
	// Class도 C++에서 사용자가 정의한 자료형이다.
	
	// 접근 제한 지정장
	// private, protected(상속), public

private:
	int m_i;
	float m_f;

public:
	void SetInt(int i)
	{
		m_i = i;
	}

public:
	// 생성자
	// 이니셜라이져(생성과 동시에 작업을 함)
	CMy()
		: m_i(100) // 이게 이니셜라이져임
		, m_f(3.14f)
	{
		// m_i = 100; // 이건 진정한 초기화가 아님, 생성자가 이미 만들고 그 만들어진 곳에 100을 넣으라는 작업이므로 2단계가 되기 때문이다.
	}


	// 소멸자
	~CMy()
	{

	}

	// C++ 구조상 생성자와 소멸자를 작성안하면 컴파일러가 자동으로 채운다. 단 아무기능이 없다.
};

void Test()
{

}



int main()
{
	// C++ 클래스 특징
	// 생성자, 소멸자
	// 객체 생성, 소멸 시 자동으로 호출
	// 직접 만들지 않으면 기본 생성자, 기본 소멸자가 만들어짐
	
	// 멤버함수
	// 해당클래스가 사용하는 전용 함수
	// 해당클래스의 객체가 필요함

	Test();

	// CMy::SetInt(1000); // CMy라는 클래스의 함수를 :: 범위로 지정해서 가져올 수 있다. 하지만 해당 클래스의 객체가 불러올 수 있다.

	tArr arr = {};
	InitArr(&arr);
	PushBack(&arr, 10);

	ReleaseArr(&arr);


	CMy c; // 생성자는 객체가 만들어질때 자동으로 호출되는 기능이다.
	// c.m_i = 0;
	c.SetInt(10);

	return 0;
}