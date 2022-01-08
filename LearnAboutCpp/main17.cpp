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

#define MAN 1
#define WOMAN 2

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
	// ����Ž�� - �ݵ�� Ʈ�������� ������ Ž�� ����� �ƴϴ�
	// 1. ���ĵǾ��ִ� �����Ϳ� ���밡��

	// ����Ž��Ʈ��
	// 1. ����Ž���� ��� �� �� �ְ� ��ȵ� ����Ʈ��
	// 2. ������ �Է� �� O(logN) ȿ��
	// 3. Ž�� ȿ���� O(logN)
	// 4. Ʈ���� ����� �뷱���� �������� ������ ����� �� Ž�� ȿ���� ������ �ʴ´�.
	// - �ڰ����� ��� �ʿ�(AVL, Red/Black)

	set<int> setInt; // Red/Black Tree ��� �����ϸ� �ȴ�.
	
	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);
	
	const wchar_t* pStr = L"���ڿ�";

	map<const wchar_t*, tStdInfo> mapData; // �ּҰ��� key ����ϸ� ������ �ּҸ� �־���� �Ѵ� -> ��, ���ڿ��� ã�°� �ƴ�!
	// �̷��� ���� ���� : C++���� ���ڿ��� ReadRom�� ����Ǿ �����ǰ� ���� �ּҸ� �Ѱ��ִ� ������� �۵��Ѵ�.

	tStdInfo info(L"ȫ�浿", 18, MAN);
	tStdInfo info2(L"������", 25, WOMAN);

	mapData.insert(make_pair(L"ȫ�浿", info)); // map ���ȿ� �̸� + �����͸� ��� �ִ� make_pair -> ��, ���ȿ��� ���� pair�� ����ִ�.
	mapData.insert(make_pair(L"������", info2));

	map<const wchar_t*, tStdInfo>::iterator mapiter; // pair ��� ����ü�� �״�� ���ڸ� �ΰ�޾� ��������� iterator�� �� pair��� ����ü�� ����ų�Ű� pair�ȿ��� key�� ������ ����ִ�.
	mapiter = mapData.find(L"ȫ�浿"); // �����͸� ����Ű�� iterator�� ��ȯ��
	// ���� ���� �����͸� ã���� iterator�� end�� ��ȯ�Ѵ�.

	_wsetlocale(LC_ALL, L"korean");

	// ã�� ���ߴ�.
	if (mapiter == mapData.end())
	{
		wcout << L"�����͸� ã�� �� �����ϴ�." << endl;
	}
	else
	{
		wcout << L"�̸� : " << mapiter->second.szName << endl;
		wcout << L"�̸� : " << mapiter->second.age << endl;
		wcout << L"���� : ";
		if (MAN == mapiter->second.gender)
		{
			wcout << L"����" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"����" << endl;
		}
		else
		{
			wcout << L"�� �� ����" << endl;
		}
	}

	(*mapiter).first; // pair�̱� ������ �ȿ� �����ؾ� �Ǵµ� �װ� first�� second�� ������� �ִ�.
	(*mapiter).second;
	mapiter->first; // �� -> �����ڵ� ����������
	mapiter->second;

	map<wstring, tStdInfo> mapStdInfo; // ���ڿ� Ŭ������ key�� ����ϸ� ���ڿ��� ã�� �� �ִ�.

	wstring str; // ���ڿ� Ŭ������ ���ڿ��� ��ü ��ü�� �����Ѵ�.
	// �Ʒ��� ���� ���ڿ��� �̾���� �� �� �ְ�, �ε��� ���ٵ� �����ϰ�, ������ �����ϴ�. ��, �����Ҵ����� ���� �� ���̴�
	// ���ڿ� Ư���� ���� ������ ���������� �������̴�. ��, �����迭�� ����� �� �̴�.
	str = L"abcdef";
	str += L"hijk";
	str += L"lmnop";
	str[1] = L'c';

	str = L"asdfksdhgkfhdkwfhksdhgkshwg";

	// �񱳿����ڵ� �����Ǿ� �־ ���ڿ� ��ü�� �񱳰� �����ϴ�.
	// �̴� �񱳿����ڰ� �����Ǿ� �־ map�� key�� �־����� �񱳰� �̷������ ���̴�.
	wstring str2;

	if (str < str2)
	{

	}

	// ���� ���� ���� �ڷ�ü�� map�� key�� ������ ��� �ɱ�?
	// �񱳿����ڰ� ������ map�� key�� ������ �ȵȴ�.
	map<MyClass, tStdInfo> mapTestInfo;
	MyClass a;
	mapTestInfo.insert(make_pair(a, info)); // Error	C2676	binary '<': 'const _Ty' does not define this operator or a conversion to a type acceptable to the predefined operator


	CBST<int, int> bstint;

	tPair<int, int> pair;
	
	pair.first = 100;
	bstint.insert(pair);

	pair.first = 150;
	bstint.insert(pair);
	
	pair.first = 50;
	bstint.insert(pair);


	return 0;
}