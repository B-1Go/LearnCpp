
#include <map>
#include <set>

#include <string>
#include <iostream>

using::std::cout;
using::std::endl;

class CParent
{
protected:
	int m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}

public:
	CParent()
		: m_i(0)
	{
		cout << "CParent 생성자 입니다." << endl;
	}
	CParent(int _a)
		: m_i(_a)
	{}
	~CParent()
	{}
};

class CChild : public CParent
{
private:
	float m_f;

public:
	void SetFloat(float _f)
	{
		m_f = _f;
		m_i = 100;
	}

public:
	CChild()
		: CParent(1000) // 즉, 초기화 하기 전에 CParent() 생성자가 생략 되어 있다고 보면 된다. -> 컴파일러가 무조건 순서를 정해놨다. 오버로딩 함수를 이용하고 싶으면 인자를 넣어서 명시해줘야 된다.
		, m_f(0.f) // 각 부분의 초기화는 각 class의 생성자가 처리한다. -> 순서는 어떻게 될까??
		// 주체가 되는 부분 부터 호출을 한다. 그러나 상속받은 생성자를 먼저 종료하기 때문에 CParent가 먼저 호출 된거 처럼 보인다.
	{
		m_i = 0;
		cout << "CChild 생성자 입니다." << endl;
	}
	~CChild()
	{}
};

class CChildChild : public CChild
{
private:
	long long m_ll;
	// 메모리가 상속받은 순서대로 붙어서 만들어진다. CParent+CChild+CChildChild -> 이게 다형성에서 설명할 중요한 이유다.
};

void FuncA()
{
	cout << "Function A" << endl;
}

void FuncB()
{
	FuncA();

	cout << "Function A" << endl;
}

int main()
{
	FuncB();

	// 객체지향 언어 특징
	// 1. 캡슐화 (은닉성)
	// 2. 상속
	// 3. 다형성
	// 4. 추상화

	// CParent parent;
	CChild child;

	// parent.SetInt(10);
	child.SetInt(10);

	// 상속
	// 자식 or 부모 클래스는 상속관계에서 다른 클래스 멤버를 초기화 할 수 없다.
	// 생성자 호출 순서 자식 -> 부모
	// 생성자 실행 순서, 초기화 순서 부모 -> 자식

	return 0;
}