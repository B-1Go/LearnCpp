
#include <stdio.h>

// 함수
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

// 재귀함수
// 가독성, 구현의 용이
// 탈출조건필수, 함수를 변수처럼 사용 & 함수 호출 및 해제 비용 으로 성능저하

// 재귀함수 팩토리얼
int Factorial_Re(int _iNum)
{
	if (_iNum < 2)
	{
		return 1;
	}
	return _iNum * Factorial_Re(_iNum - 1);
}

// 피보나치 수열
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

// 피보나치 수열 재귀함수
// 굉장히 느리기 때문에 "꼬리재귀" 같은 해결 방법이 있다고 한다.[심화]
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

	return 0;
}