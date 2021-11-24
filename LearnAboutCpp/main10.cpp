#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#include <assert.h>

// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(코드)

// 함수의 오버로딩
// 동일한 함수명 이지만, 인자값의 자료형이나 갯수를 다르게 해서 사용할 수 있다.
// 주의: 함수의 오버라이딩(나중에 헷갈리는 단골 손님)
void Test(int a)
{

}
void Test(float a)
{

}

typedef struct _tagMyST
{
	int a; // 구조체의 멤버라고 함.
	float f; 
}MYST;


unsigned int GetLength(const wchar_t* _pStr)
{
	// 문자 개수 체크 용도
	int i = 0;
	while (true)
	{
		wchar_t c = *(_pStr + i); // 편한 표현 방식 _pStr[i]

		if ('\0' == c) // 상수를 왼쪽에 두는 이유는 비교문 작성에 = 이런 오타가 날 수 있기 때문이다. ex) c = '\0'
		{
			break;
		}
		++i;
	}
	return i;
}

void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	// 예외처리
	// 이어붙인 최종 문자열 길이가, 목적지 저장 공간을 넘어서려는 경우
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);

	if (_iBufferSize < iDestLen + iSrcLen + 1)
	{
		assert(nullptr);
	}

	// 문자열 이어 붙이기
	// 1. Dest 문자열의 끝을 확인(문자열이 이어 붙을 시작 위치)
	iDestLen; // Dest 문자열 끝 인덱스

	// 2. 반복적으로 Src 문자열을 Dest 끝 위치에 붙치기
	// 3. Src 문자열의 끝을 만나면 반복 종료
	for (int i = 0; i < iSrcLen + 1; ++i)
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}
}

int StrRet(const wchar_t* _pLeft, const wchar_t* _pRight)
{
	// 예외처리
	// 문자열이 다르면 경고 메세지
	int iLeft = GetLength(_pLeft);
	int iRight = GetLength(_pRight);
	int iLen = iLeft;
	int chk = 0;

	if (iLeft < iRight)
	{
		iLen = iLeft;
		chk = -1;
	}
	else
	{
		iLen = iRight;
		chk = 1;
	}

	// 비교하기
	for (int i = 0; i < iLen; i++)
	{
		if (*(_pLeft + i) == *(_pRight + i))
		{
			continue;
		}
		else if (*(_pLeft + i) < *(_pRight + i))
		{
			chk = -1;
			break;
		}
		else
		{
			chk = 1;
			break;
		}
	}

	return chk;
}

// 풀이
int StrCmp(const wchar_t* _left, const wchar_t* _right)
{
	int leftLen = GetLength(_left);
	int rightLen = GetLength(_right);

	int iReturn = leftLen;
	int iLoop = 0;

	if (leftLen < rightLen)
	{
		iLoop = leftLen;
		iReturn = -1;
	}
	else if (leftLen > rightLen)
	{
		iLoop = rightLen;
		iReturn = 1;
	}

	for (int i = 0; i < iLoop; ++i)
	{
		if (_left[i] < _right[i])
		{
			return -1;
		}
		else if (_left[i] > _right[i])
		{
			return 1;
		}
	}

	return iReturn;
}


int main()
{
	wchar_t szName[10] = L"Raimond";

	// int iLen = wcslen(szName);
	int iLen = GetLength(szName);

	// 함수의 오버로딩
	Test(10);
	Test(3.14f);


	// 문자열 이어 붙이기
	wchar_t szString[10] = L"abc";
	// wcscat_s(szString, 100, L"def");
	StrCat(szString, 10, L"def");

	// 과제
	int Ret = wcscmp(L"abc", L"aba");

	int test = StrRet(L"abc", L"abad");

	int iRet = StrCmp(L"abc", L"abcdef");


	// 구조체와 포인터
	MYST s = {};

	MYST* pST = &s;

	(*pST).a = 100;
	(*pST).f = 3.14f;

	pST->a = 100;
	pST->f = 3.14f;

	return 0;
}

// 단축키
// Ctrl + Shift + Spacebar