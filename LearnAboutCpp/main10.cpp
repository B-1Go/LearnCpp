#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

#include <assert.h>

// �޸� ����
// 1. ����
// 2. ������
// 3. ��
// 4. ROM(�ڵ�)

// �Լ��� �����ε�
// ������ �Լ��� ������, ���ڰ��� �ڷ����̳� ������ �ٸ��� �ؼ� ����� �� �ִ�.
// ����: �Լ��� �������̵�(���߿� �򰥸��� �ܰ� �մ�)
void Test(int a)
{

}
void Test(float a)
{

}


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

void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);

	if (_iBufferSize < iDestLen + iSrcLen + 1)
	{
		assert(nullptr);
	}

	// ���ڿ� �̾� ���̱�

}

int main()
{
	wchar_t szName[10] = L"Raimond";

	// int iLen = wcslen(szName);
	int iLen = GetLength(szName);

	// �Լ��� �����ε�
	Test(10);
	Test(3.14f);


	// ���ڿ� �̾� ���̱�
	wchar_t szString[100] = L"abc";


	wcscat_s(szString, 100, L"def");

	return 0;
}

// ����Ű
// Ctrl + Shift + Spacebar