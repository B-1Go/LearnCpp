#include <stdio.h>

int Add(int a, int b)
{
	return a + b;
}



//함수
int main()
{
	int Data = Add(100, 200);

	// 반복문
	// for()
	//for (/*반복자 초기화(여기는 한번만 실행됨)*/ ; /*반복문 조건 체크(참,거짓)*/ ; /*반복자 변경*/)
	//{

	//}

	// 0, 1, 2, 3
	for (int i = 0; i < 2; ++i)
	{

		if (i % 2 == 1)
		{
			continue;
		}

		printf("Output Test\n");

		//continue;
		// 이걸 만나면 아래 코드를 실행하지 않고 다음으로 넘어간다

		//break;
		// 이걸 만나면 for문을 나간다.
	}


	/*int i = 0;
	while (i<2)
	{
		printf("Output Test\n");
		++i;

		continue;

		break;
	}*/

	// while()


	// 콘솔
	// printf()
	printf("abcdf %d \n", 10); // %d: 정수형 타입 치환문자
	printf("abcdf %f \n", 3.14f); // 실수형도 가능 대신 %f로 해줘야됨

	for (int i = 0; i < 10; i++)
	{
		printf("Output i : %d \n", i);
	}

	// scanf()
	int iInput = 0;
	scanf_s("%d", &iInput); // scanf_save.ver 이라고 강의해서 말함 나중에 찾아보자

	return 0;
}

// 비주얼스튜디오 편리한 기능
// 단축키
// 지정 주석: Ctrl + k, c
// 지정 주석풀기: Ctrl + k, u
// Alt + Drang: 원하는 부분만 지정

// 디버깅
// 디벙깅 시작 : F5
// 다음 중단점까지 코드 실행 : F5
// 중단점 생성 및 해제 : F9 (14번째에 걸면 14번 실행 직전을 의미한다)
// 디버징 중 + 구문 수행 : F10
// 디버징 중 + 구문 수행(함수 진임) : F11 (진짜 하나하나 작은 단위로 쪼개서 실행)
// 조사식 황용하기 디버그 + 창 : 호출스택, 스레드, 모듈, 프로세스 등등
// 디버깅 종료 : Shift + F5

// 실시간으로 실행하는 방법은 나중에 알아봄
// 컴파일러가 코드를 분석하는 순간 중단점을 걸었다고 해도 최소한의 작업은 실행함
// ex) 필요한 변수들에게 메모리 할당을 다 해놓는다.