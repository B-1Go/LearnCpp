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
	// 형태가 같아도 함수 뒤에 const가 붙냐 안붙냐에 따라 다른 함수로 취급된다. -> 나중에 설명
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
	// 이진탐색 - 반드시 트리에서만 가능한 탐색 방식은 아니다
	// 1. 정렬되어있는 데이터에 적용가능

	// 이진탐색트리
	// 1. 이진탐색을 사용 할 수 있게 고안된 이진트리
	// 2. 데이터 입력 시 O(logN) 효율
	// 3. 탐색 효율은 O(logN)
	// 4. 트리의 모양이 밸런스가 유지되지 않으면 제대로 된 탐색 효율이 나오지 않는다.
	// - 자가균형 기능 필요(AVL, Red/Black)

	set<int> setInt; // Red/Black Tree 라고 생각하면 된다.
	
	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);
	
	const wchar_t* pStr = L"문자열";

	map<const wchar_t*, tStdInfo> mapData; // 주소값을 key 사용하면 동일한 주소를 넣어줘야 한다 -> 즉, 문자열로 찾는게 아님!
	// 이렇게 만든 이유 : C++에서 문자열은 ReadRom에 저장되어서 관리되고 따라서 주소를 넘겨주는 방식으로 작동한다.

	tStdInfo info(L"홍길동", 18, MAN);
	tStdInfo info2(L"이지혜", 25, WOMAN);

	mapData.insert(make_pair(L"홍길동", info)); // map 노드안에 이름 + 데이터를 묶어서 넣는 make_pair -> 즉, 노드안에는 묶인 pair가 들어있다.
	mapData.insert(make_pair(L"이지혜", info2));

	map<const wchar_t*, tStdInfo>::iterator mapiter; // pair 라는 구조체가 그대로 인자를 인계받아 만들어졌고 iterator는 그 pair라는 구조체를 가리킬거고 pair안에는 key와 데이터 들어있다.
	mapiter = mapData.find(L"홍길동"); // 데이터를 가리키는 iterator를 반환함
	// 만약 없는 데이터를 찾으면 iterator는 end를 반환한다.

	_wsetlocale(LC_ALL, L"korean");

	// 찾지 못했다.
	if (mapiter == mapData.end())
	{
		wcout << L"데이터를 찾을 수 없습니다." << endl;
	}
	else
	{
		wcout << L"이름 : " << mapiter->second.szName << endl;
		wcout << L"이름 : " << mapiter->second.age << endl;
		wcout << L"성별 : ";
		if (MAN == mapiter->second.gender)
		{
			wcout << L"남자" << endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			wcout << L"여자" << endl;
		}
		else
		{
			wcout << L"알 수 없음" << endl;
		}
	}

	(*mapiter).first; // pair이기 때문에 안에 접근해야 되는데 그건 first와 second로 만들어져 있다.
	(*mapiter).second;
	mapiter->first; // 이 -> 연산자도 구현되있음
	mapiter->second;

	map<wstring, tStdInfo> mapStdInfo; // 문자열 클래스를 key로 사용하면 문자열로 찾을 수 있다.

	wstring str; // 문자열 클래스는 문자열을 자체 객체에 보관한다.
	// 아래와 같이 문자열을 이어붙일 수 도 있고, 인덱스 접근도 가능하고, 수정도 가능하다. 즉, 동적할당으로 관리 할 것이다
	// 문자열 특성상 같은 공간에 연속적으로 있을것이다. 즉, 가변배열과 비슷할 것 이다.
	str = L"abcdef";
	str += L"hijk";
	str += L"lmnop";
	str[1] = L'c';

	str = L"asdfksdhgkfhdkwfhksdhgkshwg";

	// 비교연산자도 구현되어 있어서 문자열 자체로 비교가 가능하다.
	// 이는 비교연산자가 구현되어 있어서 map에 key로 넣었을때 비교가 이루어지는 것이다.
	wstring str2;

	if (str < str2)
	{

	}

	// 만약 내가 만든 자료체를 map의 key로 넣으면 어떻게 될까?
	// 비교연산자가 없으면 map의 key로 동작이 안된다.
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