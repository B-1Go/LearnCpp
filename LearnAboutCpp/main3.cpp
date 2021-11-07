
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

// ����Լ� ���丮��
int Factorial_Re(int _iNum)
{
	if (_iNum < 2)
	{
		return 1;
	}
	return _iNum * Factorial_Re(_iNum - 1);
}

// �Ǻ���ġ ����
// 1 1 2 3 5 8 13 21 34 55....
int Fibonacci(int _iNum)
{
	if (1 == _iNum || 2 == _iNum)
	{
		return 1;
	}
	int iPrev1 = 1;
	int iPrev2 = 1;
	int iValue;
	for (int j = 1;j < _iNum - 1; ++j)
	{
		iValue = iPrev1 + iPrev2;
		iPrev1 = iPrev2;
		iPrev2 = iValue;
	}
	return iValue;
}

// �Ǻ���ġ ���� ����Լ�
// ������ ������ ������ "�������" ���� �ذ� ����� �ִٰ� �Ѵ�.[��ȭ]
int Fibonacci_Re(int _iNum)
{
	if (1 == _iNum || 2 == _iNum)
	{
		return 1;
	}
	return Fibonacci_Re(_iNum - 1) + Fibonacci_Re(_iNum - 2);
}

int main()
{
	int iValue = Factorial(4);
	iValue = Factorial(10);
	iValue = Factorial_Re(10);

	iValue = Fibonacci(10);

	iValue = Fibonacci_Re(3);


	// �迭
	// �޸𸮰� ���������� �������̴�.
	int iArray[10] = { };

	iArray[4] = 10;
	// iArray[12] = 10;
	// �ε��� ������ �ʰ��ؼ� �����ϰ� �Ǹ� main �Լ� ���� �޸𸮿� �ٸ� ������ �����Ͽ� ���� ������ �� ���ִ�.
	// ������ ��� ���� �ε��� ���� ������ �� ��´�. ����� ��忡���� ���� ������ �������� ���� �Ǳ⵵ �Ѵ�.
	// ��, ������ �� ����, �� �� ���� �ִ�.
	


	// �����͸� �˾ƾ� �迭�̶�� �� ����� �� �� �ִ�.
	// ���� �Ẹ�� �پ��� ������ �׾ƾ� �Ѵ�.


	return 0;
}