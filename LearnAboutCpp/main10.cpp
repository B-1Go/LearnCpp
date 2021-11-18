#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(코드)

int main()
{
	wchar_t szName[10] = L"Raimond";

	int iLen = wcslen(szName);

	return 0;
}

// 단축키
// Ctrl + Shift + Spacebar