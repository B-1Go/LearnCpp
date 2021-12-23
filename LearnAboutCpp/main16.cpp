#include <iostream>

#include "CList.h"

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
	CList<float> list;

	for (int i = 0; i < 4; i++)
	{
		list.push_back(i);
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

	return 0;
}