#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(코드)

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

int main()
{
	wchar_t szName[10] = L"Raimond";

	// int iLen = wcslen(szName);
	int iLen = GetLength(szName);

	// 문자열 이어 붙이기
	// wcscat_s();

	return 0;
}

// 단축키
// Ctrl + Shift + Spacebar