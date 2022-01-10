#include <iostream>

#include <map>
#include <set>

#include <string>

#include "CBST.h"

using std::wcout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;

using std::wstring;

// ������
enum class MY_TYPE
{
	TYPE_1, // 0
	TYPE_2, // 1
	TYPE_3, // 2
	TYPE_4, // 3
	TYPE_5 = 100,
	TYPE_6, // 101
};

enum class OTHER_TYPE
{
	TYPE_1,
};

// ��ó��(#define)�� ������ ����ѵ� ���� ���̰� �ֳ�
// �ϴ� #define�� �����Ϸ��� �׳� ���ڷ� �ٲ������
// ����׽� int a = CLASS_1 -> int a = 0; �̷������� ���δ�.
// ������ enum�� ����ϸ� ����׽ÿ� TYPE_1�̶�� ���⶧����
// ���߿� �ڵ带 �����ϰų� ������ ã�µ� ���� ū ���̰� ����.
#define CLASS_1 0
#define CLASS_2 1
#define CLASS_3 2
#define CLASS_4 3
#define CLASS_5 4
#define CLASS_6 5


struct tStdInfo
{
	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;

	tStdInfo()
		: szName{}
		, age(0)
		, gender(0)
	{
	}

	tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gneder)
		: szName{}
		, age(_age)
		, gender(_gneder)
	{
		wcscpy_s(szName, _pName);
	}
};

struct pair
{
	const wchar_t* first;
	tStdInfo second;
};

class MyClass
{
private:
	int a;

public:
	// ���°� ���Ƶ� �Լ� �ڿ� const�� �ٳ� �ȺٳĿ� ���� �ٸ� �Լ��� ��޵ȴ�. -> ���߿� ����
	//bool operator < (const MyClass& _other) const
	//{
	//	if (a < _other.a)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}

	bool operator < (const MyClass& _other) const
	{
		if (a < _other.a)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator > (const MyClass& _other) const
	{
		if (a > _other.a)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

int main()
{
	// �׳� enum�� ���� �Ǹ� ���� �����Ϸ��� ��� ����.
	// cnum class ���� �Ǹ� Ŭ�������� Ȯ���ϰ� �ؾߵǸ�
	// ���������� �ѱ涧�� �ݵ�� ĳ������ ������Ѵ�.
	int a = (int)MY_TYPE::TYPE_1;

	OTHER_TYPE::TYPE_1;

	// ����Ž�� - �ݵ�� Ʈ�������� ������ Ž�� ����� �ƴϴ�
	// 1. ���ĵǾ��ִ� �����Ϳ� ���밡��

	// ����Ž��Ʈ��
	// 1. ����Ž���� ��� �� �� �ְ� ��ȵ� ����Ʈ��
	// 2. ������ �Է� �� O(logN) ȿ��
	// 3. Ž�� ȿ���� O(logN)
	// 4. Ʈ���� ����� �뷱���� �������� ������ ����� �� Ž�� ȿ���� ������ �ʴ´�.
	// - �ڰ����� ��� �ʿ�(AVL, Red/Black)
	CBST<int, int> bstint;

	bstint.insert(make_bstpair(100, 0));
	bstint.insert(make_bstpair(150, 0));
	bstint.insert(make_bstpair(50, 0));

	CBST<int, int>::iterator Iter = bstint.begin();
	Iter = bstint.find(150);


	//map<int, int> mapInt;
	//mapInt.insert(make_pair(100, 100));

	//map<int, int>::iterator mapiter = mapInt.find(100);
	//if (mapiter == mapInt.end())
	//{
	//	wcout << "ã�� �� ����" << endl;
	//}

	//(*Iter).first;
	//Iter->first;

	//(*Iter).second;
	//Iter->second;

	//tPair<int, int> pair;

	//tPair<int, int>* pPair = &pair;
	//pPair->first;
	//pPair->second;

	//for (Iter = bstint.begin(); Iter != bstint.end(); ++Iter)
	//{
	//	wcout << Iter->first << Iter->second << endl;
	//}

	bstint.insert(make_bstpair(25, 0));
	bstint.insert(make_bstpair(75, 0));
	bstint.insert(make_bstpair(125, 0));
	bstint.insert(make_bstpair(175, 0));

	Iter = bstint.find(25);

	Iter = bstint.erase(Iter);

	return 0;
}