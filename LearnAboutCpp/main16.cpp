#include <iostream>

#include "CArr.h"
#include "CList.h"

#include <vector>
#include <list>


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

using std::vector;
using std::list;


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



	
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);

	vecInt[0] = 100;
	vecInt.at(0); // ���͵����� �ε��� ����
	vecInt.data(); // ���͵������� �����ּ�
	vecInt.size(); // ���͵������� �ڷ᰹��
	vecInt.capacity(); // ���͵������� ������

	for (size_t i = 0; i < vecInt.size(); ++i)
	{
		cout << vecInt.at(i) << endl;
	}

	vector<int>::iterator veciter = vecInt.begin(); // ����(�����迭)�� 
	*veciter = 100;
	++veciter;
	vecInt[0] = 100;
	// vecInt.erase(); // ���ڷ� iterator�� �޴´�. ��, ���ͷ����Ͱ� ����Ű�� ���� ����ڴٴ� ���̴�.



	list<int> listInt;
	listInt.push_back(10);
	listInt.push_front(100);
	listInt.size();

	// iterator �ݺ��� (inner class)
	// Ŭ���� �ȿ� ������ Ŭ���� -> �ڷᱸ�� �ȿ� �����͸� ��ȸ �� ���� ���� ����� ������.
	list<int>::iterator iter = listInt.begin(); // �ִ� �ݺ���������
	int iData = *iter; // ��ġ ������ ó�� �����͸� ������ �� �� �ְ� ����� ���Ҵ�. (������ �����ε�)
	++iter; // ���������ͷ� ��
	iData = *iter;

	for (iter = listInt.begin(); iter != listInt.end(); ++iter) // end() : ���̽� �ε��� ó�� ������ + 1 �� �����̴�. -> ���� ����Ʈ �ȿ� ��ȸ�� �� �ȴ�.
	{ 
		cout << *iter << endl;
	}


	CArr<int> myvector;

	myvector.push_back(1);
	myvector.push_back(2);
	myvector.push_back(3);

	CArr<int>::iterator myiter = myvector.begin();

	// ++(����, ����), --, ==, !=
	for ( ; myiter != myvector.end(); ++myiter)
	{
		cout << *myiter << endl;
	}



	return 0;
};