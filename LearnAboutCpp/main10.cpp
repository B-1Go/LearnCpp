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


unsigned int GetLength(const wchar_t* _pStr)
{
	// 문자 개수 체크 용도
	int i = 0;
	while (true)
	{
		wchar_t c = *(_pStr + 1); // 편한 표현 방식 _pStr[i]

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
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);

	if (_iBufferSize < iDestLen + iSrcLen + 1)
	{
		assert(nullptr);
	}

	// 문자열 이어 붙이기

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
	wchar_t szString[100] = L"abc";


	wcscat_s(szString, 100, L"def");

	return 0;
}

// 단축키
// Ctrl + Shift + Spacebar