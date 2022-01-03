#include <iostream>

#include "CArr.h"
#include "CList.h"

#include <vector>
#include <list>


namespace MYSPACE
{
	// 네임스페이스는 말 그대로 이름을 지어주는 것이다.
	// 지금은 main() 밖에 g_int는 전역변수이다.
	// 하지만 사용할 때는 이름을 지칭해줘야 한다.
	// 이유는 개발자들이 만들어놓은 변수명을 std에 넣어두므로써 같은 변수명 충돌을 방지하기 위한것이다.
	// 따라서 사용자들이랑 겹치지 않게 할 수 있다.
	int g_int;
}

namespace OHTERSPACE
{
	int g_int;
}

// 매번 지칭해주는게 불편하기 때문에 using을 사용하면 std:: 를 안붙여도 사용이 가능하다
// 그럼 같은 변수명 출동은 어떻게 해야되냐 그래서 필요한 부분만 using std::cout; 가 가능하다
// 참고로 namespace 안에는 변수, 함수 등등 다 넣어줄 수 있다.
// using namespace std;
using std::cout;
using std::wcout;
using std::cin;
using std::endl;

using std::vector;
using std::list;


class CTest
{
	// 1. 클래스에는 보이지 않지만 자동으로 생성해주는 기능들이 있다.
	// -> 생성자, 소멸자, 복사생성자, 오퍼레이터 대입연산자

public:
	int m_i;

public:
	CTest& operator =(const CTest& _other)
	{
		m_i = _other.m_i;
		return *this;
	}

public:
	CTest()
	{

	}
	CTest(const CTest& _other)
		: m_i(_other.m_i)
	{
		// 이 복사생성자도 알아서 컴파일러가 만들어준다.
		// 그러나! 인자가 있는 생성자를 만들게 되면 기본 생성자는 컴파일러가 만들어주지 않는다.
		// 이유는 개발자가 무조건 인자를 가진 생성자로 시작하게 하고싶은데 자꾸 컴파일러가 기본 생성자를 만들게 되면 설계 의도와 맞지 않기때문에
		// 생성자를 만들게 되면 기본 생성자를 컴파일러는 만들어 주지 않는다.
	}
};



void MyEndL()
{
	wprintf(L"\n");
}

class CMyOStream
{
public:
	CMyOStream& operator << (int _idata)
	{
		wprintf(L"%d", _idata);
		return *this;
	}

	CMyOStream& operator << (const wchar_t* _pSrting)
	{
		wprintf(L"%s", _pSrting);
		return *this;
	}

	CMyOStream& operator << (void(*_pFunc)(void))
	{
		_pFunc();
		return *this;
	}

	CMyOStream& operator >> (int& _idata) // 레퍼런스사용됨!
	{
		scanf_s("%d", &_idata);
		return *this;
	}
};

CMyOStream mycout;


int main()
{
	CList<float> List;

	for (int i = 0; i < 4; i++)
	{
		List.push_back(i);
	}


	CList<int> ilist;

	for (int i = 0; i < 4; i++)
	{
		ilist.push_back(i);
	}

	//// C printf
	//std::cout << "안녕" << 10 << std::endl;


	//// C scanf
	//int iInput = 0;
	//std::cin >> iInput;

	MYSPACE::g_int = 0;

	// 표준언어가 한글이 아니여서 아스키코드를 한글로 설정함
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	mycout << L"한글";

	/*int a = 0;
	mycout >> a;*/
	
	mycout << 10 << L" " << 20 << L" " << L"문자열" << MyEndL;



	
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);

	vecInt[0] = 100;
	vecInt.at(0); // 백터데이터 인덱스 접근
	vecInt.data(); // 백터데이터의 시작주소
	vecInt.size(); // 백터데이터의 자료갯수
	vecInt.capacity(); // 백터데이터의 허용범위

	for (size_t i = 0; i < vecInt.size(); ++i)
	{
		cout << vecInt.at(i) << endl;
	}

	vector<int>::iterator veciter = vecInt.begin(); // 벡터(가변배열)는 iterator가 가르키던 메모리주소가 재할당과 같은 메모리 주소 변화가 일어나면 문제로 보고있다.
	*veciter = 100;
	++veciter;
	vecInt[0] = 100;
	// vecInt.erase(); // 인자로 iterator를 받는다. 즉, 이터레이터가 가르키는 곳을 지우겠다는 뜻이다.



	list<int> listInt;
	listInt.push_back(10);
	listInt.push_front(100);
	listInt.size();

	// iterator 반복자 (inner class)
	// 클래스 안에 구현된 클래스 -> 자료구조 안에 데이터를 순회 및 수정 등의 기능을 제공함.
	list<int>::iterator iter = listInt.begin(); // 애는 반복자이지만
	int iData = *iter; // 마치 포인터 처럼 데이터를 역참조 할 수 있게 만들어 놓았다. (연산자 오버로딩)
	++iter; // 다음데이터로 감
	iData = *iter;

	for (iter = listInt.begin(); iter != listInt.end(); ++iter) // end() : 파이썬 인덱스 처럼 마지막 + 1 된 개념이다. -> 따라서 리스트 안에 순회가 다 된다.
	{ 
		cout << *iter << endl;
	}


	CArr<int> myvector;

	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);

	CArr<int>::iterator myiter = myvector.begin();

	// ++(전위, 후위), --, ==, !=
	for ( ; myiter != myvector.end(); ++myiter)
	{
		cout << *myiter << endl;
	}

	myiter = myvector.begin();
	// --myiter;
	// myiter--;

	// int iData = *(++myiter);
	// int iData = *(myiter++);
	
	
	// 시험에 단골로 나오는 개념!!!
	CTest t1;
	t1.m_i = 100;

	CTest t2(t1); // 복사생성자 호출

	CTest t3 = t2; // 이건 대입연산자 처럼 보이지만 컴파일러가 알아서 CTest t3(t2) 복사생성자로 바꾼다.


	// vector::erase
	vector<int> vecInt2;

	vecInt2.push_back(100);
	vecInt2.push_back(200);
	vecInt2.push_back(300);
	vecInt2.push_back(400);

	vector<int>::iterator veciter2 = vecInt2.begin();
	veciter2 = vecInt2.erase(veciter2); // erase의 반환 타입은 itrator이므로, 단순히 지우기만 하면 안되고 veciter가 받아야한다.
	int i = *veciter2;


	// 실제 리스트의 insert 동작 방식 보기 위해서 만듬
	list<int> intlist;

	intlist.push_back(100);
	intlist.push_back(100);

	list<int>::iterator it = intlist.begin();
	it = intlist.insert(++it, 200); // iterator 로 리턴되는 이유는 삽입한 데이터를 지칭하기 위함이며, 가르키는 대상의 앞쪽으로 들어간다 (여러가지 종류가 있음)


	// =============
	// list iterator
	// =============
	CList<int> mylist;

	mylist.push_back(100);
	mylist.push_back(200);
	mylist.push_back(300);

	CList<int>::iterator listiter = mylist.begin();
	int l = *listiter;

	*listiter = 150;

	cout << "==================" << endl;
	cout << "list iterator test" << endl;
	cout << "==================" << endl;
	for (listiter = mylist.begin(); listiter != mylist.end(); ++listiter)
	{
		cout << *listiter << endl;
	}



 	return 0;
};