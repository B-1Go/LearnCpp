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

// 열거형
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

// 전처리(#define)과 굉장히 비슷한데 무슨 차이가 있냐
// 일단 #define은 컴파일러가 그냥 숫자로 바꿔버린다
// 디버그시 int a = CLASS_1 -> int a = 0; 이런식으로 보인다.
// 하지만 enum을 사용하면 디버그시에 TYPE_1이라고 남기때문에
// 나중에 코드를 수정하거나 오류를 찾는데 아주 큰 차이가 난다.
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
	// 그냥 enum을 쓰게 되면 요즘 컴파일러는 경고를 띄운다.
	// cnum class 쓰게 되면 클래스명을 확실하게 해야되며
	// 정수형으로 넘길때도 반드시 캐스팅을 해줘야한다.
	int a = (int)MY_TYPE::TYPE_1;

	OTHER_TYPE::TYPE_1;

	// 이진탐색 - 반드시 트리에서만 가능한 탐색 방식은 아니다
	// 1. 정렬되어있는 데이터에 적용가능

	// 이진탐색트리
	// 1. 이진탐색을 사용 할 수 있게 고안된 이진트리
	// 2. 데이터 입력 시 O(logN) 효율
	// 3. 탐색 효율은 O(logN)
	// 4. 트리의 모양이 밸런스가 유지되지 않으면 제대로 된 탐색 효율이 나오지 않는다.
	// - 자가균형 기능 필요(AVL, Red/Black)
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
	//	wcout << "찾을 수 없음" << endl;
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