#include <iostream>

#include "CList.h"

namespace MYSPACE
{
	// ���ӽ����̽��� �� �״�� �̸��� �����ִ� ���̴�.
	// ������ main() �ۿ� g_int�� ���������̴�.
	// ������ ����� ���� �̸��� ��Ī����� �Ѵ�.
	// ������ �����ڵ��� �������� �������� std�� �־�ιǷν� ���� ������ �浹�� �����ϱ� ���Ѱ��̴�.
	// ���� ����ڵ��̶� ��ġ�� �ʰ� �� �� �ִ�.
	int g_int;
}

namespace OHTERSPACE
{
	int g_int;
}

// �Ź� ��Ī���ִ°� �����ϱ� ������ using�� ����ϸ� std:: �� �Ⱥٿ��� ����� �����ϴ�
// �׷� ���� ������ �⵿�� ��� �ؾߵǳ� �׷��� �ʿ��� �κи� using std::cout; �� �����ϴ�
// ����� namespace �ȿ��� ����, �Լ� ��� �� �־��� �� �ִ�.
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

	CMyOStream& operator >> (int& _idata) // ���۷�������!
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
	//std::cout << "�ȳ�" << 10 << std::endl;


	//// C scanf
	//int iInput = 0;
	//std::cin >> iInput;

	MYSPACE::g_int = 0;

	// ǥ�ؾ� �ѱ��� �ƴϿ��� �ƽ�Ű�ڵ带 �ѱ۷� ������
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");

	mycout << L"�ѱ�";

	/*int a = 0;
	mycout >> a;*/
	
	mycout << 10 << L" " << 20 << L" " << L"���ڿ�" << MyEndL;

	return 0;
}