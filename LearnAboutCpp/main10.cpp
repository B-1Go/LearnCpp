#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

// �޸� ����
// 1. ����
// 2. ������
// 3. ��
// 4. ROM(�ڵ�)

unsigned int GetLength(const wchar_t* _pStr)
{
	// ���� ���� üũ �뵵
	int i = 0;
	while (true)
	{
		wchar_t c = *(_pStr + 1); // ���� ǥ�� ��� _pStr[i]

		if ('\0' == c) // ����� ���ʿ� �δ� ������ �񱳹� �ۼ��� = �̷� ��Ÿ�� �� �� �ֱ� �����̴�. ex) c = '\0'
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

	// ���ڿ� �̾� ���̱�
	// wcscat_s();

	return 0;
}

// ����Ű
// Ctrl + Shift + Spacebar