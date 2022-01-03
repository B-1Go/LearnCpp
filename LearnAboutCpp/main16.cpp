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


class CTest
{
	// 1. Ŭ�������� ������ ������ �ڵ����� �������ִ� ��ɵ��� �ִ�.
	// -> ������, �Ҹ���, ���������, ���۷����� ���Կ�����

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
		// �� ��������ڵ� �˾Ƽ� �����Ϸ��� ������ش�.
		// �׷���! ���ڰ� �ִ� �����ڸ� ����� �Ǹ� �⺻ �����ڴ� �����Ϸ��� ��������� �ʴ´�.
		// ������ �����ڰ� ������ ���ڸ� ���� �����ڷ� �����ϰ� �ϰ������ �ڲ� �����Ϸ��� �⺻ �����ڸ� ����� �Ǹ� ���� �ǵ��� ���� �ʱ⶧����
		// �����ڸ� ����� �Ǹ� �⺻ �����ڸ� �����Ϸ��� ����� ���� �ʴ´�.
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

	vector<int>::iterator veciter = vecInt.begin(); // ����(�����迭)�� iterator�� ����Ű�� �޸��ּҰ� ���Ҵ�� ���� �޸� �ּ� ��ȭ�� �Ͼ�� ������ �����ִ�.
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

	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);

	CArr<int>::iterator myiter = myvector.begin();

	// ++(����, ����), --, ==, !=
	for ( ; myiter != myvector.end(); ++myiter)
	{
		cout << *myiter << endl;
	}

	myiter = myvector.begin();
	// --myiter;
	// myiter--;

	// int iData = *(++myiter);
	// int iData = *(myiter++);
	
	
	// ���迡 �ܰ�� ������ ����!!!
	CTest t1;
	t1.m_i = 100;

	CTest t2(t1); // ��������� ȣ��

	CTest t3 = t2; // �̰� ���Կ����� ó�� �������� �����Ϸ��� �˾Ƽ� CTest t3(t2) ��������ڷ� �ٲ۴�.


	// vector::erase
	vector<int> vecInt2;

	vecInt2.push_back(100);
	vecInt2.push_back(200);
	vecInt2.push_back(300);
	vecInt2.push_back(400);

	vector<int>::iterator veciter2 = vecInt2.begin();
	veciter2 = vecInt2.erase(veciter2); // erase�� ��ȯ Ÿ���� itrator�̹Ƿ�, �ܼ��� ����⸸ �ϸ� �ȵǰ� veciter�� �޾ƾ��Ѵ�.
	int i = *veciter2;


	// ���� ����Ʈ�� insert ���� ��� ���� ���ؼ� ����
	list<int> intlist;

	intlist.push_back(100);
	intlist.push_back(100);

	list<int>::iterator it = intlist.begin();
	it = intlist.insert(++it, 200); // iterator �� ���ϵǴ� ������ ������ �����͸� ��Ī�ϱ� �����̸�, ����Ű�� ����� �������� ���� (�������� ������ ����)


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