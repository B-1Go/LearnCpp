
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

	virtual void output()
	{
		cout << "Parent" << endl;
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
	{
		cout << "CParent 소멸자 입니다." << endl;
	}
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

	// 상속받은 부모클래스의 함수를 재정의(오버라이딩) 함
	void output()
	{
		cout << "Child" << endl;
	}

	void NewFunc()
	{
		cout << "자식만 가진 함수입니다" << endl;
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
	{
		cout << "CChild 소멸자 입니다." << endl;
		// 눈에 보이진 않지만 컴파일러가 ~CParent() 호출하는 코드를 만들기 때문에 호출이 된다!
	}
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
	//FuncA();

	cout << "Function A" << endl;
		
	FuncA();
}

int main()
{
	// FuncB();

	// 객체지향 언어 특징
	// 1. 캡슐화 (은닉성)
	// 2. 상속
	// 3. 다형성
	// 4. 추상화

	CParent parent;
	//parent.output();

	CChild child;
	//child.output();
	//child.CParent::output(); // 이럴게 부모쪽 함수를 호출 할 수 있지만, 이렇게 하면 오버라이딩한 의미가 퇴색된다.
	// parent.SetInt(10);
	//child.SetInt(10);

	// 상속
	// 자식 or 부모 클래스는 상속관계에서 다른 클래스 멤버를 초기화 할 수 없다.
	// 생성자 호출 순서 자식 -> 부모
	// 생성자 실행 순서, 초기화 순서 부모 -> 자식
	
	// 소멸자 실행 및 호출 순서, 자식 -> 부모
	
	// 결론! 상속받은 child 객체를 실행하면
	// 생성자, 소멸자 둘다 child 부터 호출이 된다. 하지만!
	// 자식 생성자는 호출만 먼저 될 뿐 실행은 부모 생성자부터 실행이 완료되고 종료되면 순차적으로 실행되고 종료된다.
	// 자식 소멸자는 호출도 먼저 되고 실행도 먼저 한다음 부모 소멸자를 호출하고 실행한다음 순차적으로 종료가 된다.

	// 오버 라이딩(오버 로딩이랑 헷갈림 주의!) -> 오버 라이딩은 상속간에 일어나는 일이다.
	// 오버라이딩이란? 부모 클래스의 멤버함수를 자식쪽에서 재정의 함으로써, 자식 클래스에 구현된 기능이 호출되도록 한다.

	
	
	// 다향성을 이해하기 위해서 상속 And 포인터를 이해하고 있어야된다.
	// 

	CParent* pParent = &parent;
	CChild* pChild = &child;

	// CParent를 상속받은 CChild의 객체를 만들면 메모리 구조상 CParent공간이 할당되고 뒤에 CChild 공간이 붙어서 할당된다.
	// 포인트 개념으로 접근을 하면 CParent* 로 CPchild를 받을 수 있다.
	// 하지만 개념적으로 보면 그 객체가 CParent인지 CChild인 구별 할 수 가 없다.
	// 그러면 그냥 CParent로 취급되니까 다향성이 아니라 그냥 통일성아닌가? 따라서 C++에서는 virtual을 지원하므로
	// CParent* pParent = &child;
	// CChild* pChild = &parent;
	

	parent.output();
	pParent = &parent;
	pParent->output();

	child.output();
	pParent = &child;
	pParent->output();

	// virtual 가상함수 -> 원리: 각 객체의 고유정보를 담아 맨 앞단에 배치고하여 비록 CParent로 접근을 해도 child()호출된 상태를 인지해서 CChild output()을 부를수 있다.

	((CChild*)pParent)->NewFunc();

	CChild* pChildt = dynamic_cast<CChild*>(pParent); // 캐스팅 실패시 nullptr을 반환함
	if (nullptr != pChildt)
	{
		pChildt->NewFunc();
	}
	
	// 다향성, 가상함수(virtual)
	// 부모 포인터 타입으로, 부모 클래스로부터 파생되는 자식클래스 객체들의 주소를 가리킬 수 있다.
	// 모든 객체를 부모 클래스 타입으로 인식하게 되기 때문에, 실제 객체가 무엇인지 알 수 없다.
	// virtual 키워드를 통해서, 각 클래스는 자신만의 고유한 가상함수 테이블을 가지게 된다.
	// 각 클래스의 객체들은 가상함수 테이블 포인터에서 해당 클래스에 맞는 테이블을 가리키게 된다.
	// 그 테이블에는 해당 클래스의 가상함수들이 등록

	// 다운 캐스팅
	// 부모 클래스에서 산언되지 않은, 오직 자식쪽에서만 추가된 함수를 호출 하고 싶을 때
	// 자식 포인터타입으로 일시적으로 캐스팅 해서 호출한다.
	// 문제가 발생 할 수 있기 때문에 dynamic_cast 로 안전하게 확인해 볼 수 있다.
	// RTTI(Run Time Type Identification or Information)

	// 추상화
	// 실제 객체를 생성할 목적의 클레스가 아닌, 상속을 통해서 구현해야할 내용을 전달하는 상속 목적으로 만들어진 클래스
	// virtual , = 0 (1 개 이상의 순수가상함수를 포함하면 추상클래스가 된다)

	return 0;
}