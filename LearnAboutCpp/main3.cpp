
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


	// 배열
	// 메모리가 물리적으로 연속적이다.
	int iArray[10] = { };

	iArray[4] = 10;
	// iArray[12] = 10;
	// 인덱스 접근을 초과해서 접근하게 되면 main 함수 스택 메모리에 다른 변수에 접근하여 값을 변경할 수 도있다.
	// 릴리즈 경우 오버 인덱스 접근 오류는 못 잡는다. 디버그 모드에서는 위와 같으면 오류없이 진행 되기도 한다.
	// 즉, 오류가 날 수도, 안 날 수도 있다.
	


	// 포인터를 알아야 배열이라는 걸 제대로 알 수 있다.
	// 많이 써보도 다양한 경험을 쌓아야 한다.


	return 0;
}