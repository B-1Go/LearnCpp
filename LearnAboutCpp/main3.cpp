
#include <stdio.h>

// �Լ�
// Factorial
int Factorial(int _iNum)
{
	int iValue = 1;
	for (int j = 0; j < _iNum - 1; ++j)
	{
		iValue *= (j + 2);
	}
	return iValue;
}

// ����Լ�
// ������, ������ ����
// Ż�������ʼ�, �Լ��� ����ó�� ��� & �Լ� ȣ�� �� ���� ��� ���� ��������


int main()
{
	int iValue = Factorial(4);
	iValue = Factorial(10);

	return 0;
}