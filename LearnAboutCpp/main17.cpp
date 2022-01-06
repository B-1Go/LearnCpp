#include <iostream>

#include <map>
#include <set>

using std::cout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;

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

	map<const wchar_t*, tStdInfo> mapData;

	tStdInfo info(L"ȫ�浿", 18, MAN);
	tStdInfo info2(L"������", 25, WOMAN);

	mapData.insert(make_pair(L"ȫ�浿", info)); // map ���ȿ� �̸� + �����͸� ��� �ִ� make_pair -> ��, ���ȿ��� ���� pair�� ����ִ�.
	mapData.insert(make_pair(L"������", info2));

	map<const wchar_t*, tStdInfo>::iterator mapiter; // pair ��� ����ü�� �״�� ���ڸ� �ΰ�޾� ��������� iterator�� �� pair��� ����ü�� ����ų�Ű� pair�ȿ��� key�� ������ ����ִ�.
	mapiter = mapData.find(L"ȫ�浿"); // �����͸� ����Ű�� iterator�� ��ȯ��
	// ���� ���� �����͸� ã���� iterator�� end�� ��ȯ�Ѵ�.

	// ã�� ���ߴ�.
	if (mapiter == mapData.end())
	{
		cout << L"�����͸� ã�� �� �����ϴ�." << endl;
	}
	else
	{

	}

	(*mapiter).first; // pair�̱� ������ �ȿ� �����ؾ� �Ǵµ� �װ� first�� second�� ������� �ִ�.
	(*mapiter).second;
	mapiter->first; // �� -> �����ڵ� ����������
	mapiter->second;

	return 0;
}