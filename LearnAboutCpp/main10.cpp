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

typedef struct _tagMyST
{
	int a; // ����ü�� ������ ��.
	float f; 
}MYST;


unsigned int GetLength(const wchar_t* _pStr)
{
	// ���� ���� üũ �뵵
	int i = 0;
	while (true)
	{
		wchar_t c = *(_pStr + i); // ���� ǥ�� ��� _pStr[i]

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
	// ����ó��
	// �̾���� ���� ���ڿ� ���̰�, ������ ���� ������ �Ѿ���� ���
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);

	if (_iBufferSize < iDestLen + iSrcLen + 1)
	{
		assert(nullptr);
	}

	// ���ڿ� �̾� ���̱�
	// 1. Dest ���ڿ��� ���� Ȯ��(���ڿ��� �̾� ���� ���� ��ġ)
	iDestLen; // Dest ���ڿ� �� �ε���

	// 2. �ݺ������� Src ���ڿ��� Dest �� ��ġ�� ��ġ��
	// 3. Src ���ڿ��� ���� ������ �ݺ� ����
	for (int i = 0; i < iSrcLen + 1; ++i)
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}
}

int StrRet(const wchar_t* _pLeft, const wchar_t* _pRight)
{
	// ����ó��
	// ���ڿ��� �ٸ��� ��� �޼���
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

	// ���ϱ�
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

// Ǯ��
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

	// �Լ��� �����ε�
	Test(10);
	Test(3.14f);


	// ���ڿ� �̾� ���̱�
	wchar_t szString[10] = L"abc";
	// wcscat_s(szString, 100, L"def");
	StrCat(szString, 10, L"def");

	// ����
	int Ret = wcscmp(L"abc", L"aba");

	int test = StrRet(L"abc", L"abad");

	int iRet = StrCmp(L"abc", L"abcdef");


	// ����ü�� ������
	MYST s = {};

	MYST* pST = &s;

	(*pST).a = 100;
	(*pST).f = 3.14f;

	pST->a = 100;
	pST->f = 3.14f;

	return 0;
}

// ����Ű
// Ctrl + Shift + Spacebar