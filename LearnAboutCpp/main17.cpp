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

	map<const wchar_t*, tStdInfo> mapData;

	tStdInfo info(L"홍길동", 18, MAN);
	tStdInfo info2(L"이지혜", 25, WOMAN);

	mapData.insert(make_pair(L"홍길동", info)); // map 노드안에 이름 + 데이터를 묶어서 넣는 make_pair -> 즉, 노드안에는 묶인 pair가 들어있다.
	mapData.insert(make_pair(L"이지혜", info2));

	map<const wchar_t*, tStdInfo>::iterator mapiter; // pair 라는 구조체가 그대로 인자를 인계받아 만들어졌고 iterator는 그 pair라는 구조체를 가리킬거고 pair안에는 key와 데이터 들어있다.
	mapiter = mapData.find(L"홍길동"); // 데이터를 가리키는 iterator를 반환함
	// 만약 없는 데이터를 찾으면 iterator는 end를 반환한다.

	// 찾지 못했다.
	if (mapiter == mapData.end())
	{
		cout << L"데이터를 찾을 수 없습니다." << endl;
	}
	else
	{

	}

	(*mapiter).first; // pair이기 때문에 안에 접근해야 되는데 그건 first와 second로 만들어져 있다.
	(*mapiter).second;
	mapiter->first; // 이 -> 연산자도 구현되있음
	mapiter->second;

	return 0;
}