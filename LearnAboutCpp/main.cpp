// 주석
//  설명 역할, 코드로 인식되지 않는다.

int main()
{
	// 자료형 (크기 단위, 1byte = 8bit) Data Type
	// 정수형 : char(1), short(2), int(4), long(4), long long(8)
	// 실수형 : float(4), double(8)
	int i = 0;
	unsigned char c = 0; // 양의 정수만

	c = 0; // 256가지 -> 0~255
	c = 256; // 1 0000 0000 => 8개만 읽으면 0	9번째 비트는 1바이트에 담을 수 없기 때문에 무시

	// 기본적으로 signed로 되어있고 생략되있다.
	signed c1 = 0; // 256가지 -> -128~127
	// 맨끝(왼쪽끝) Most Siginficant Bit(MSD) 0: 양수, 1: 음수
	c1 = -1;

	// 컴퓨터는 모든 연산을 가산으로 처리하기 때문에
	// 음수의 접근방식을 바꿔서 생각해야 한다.
	// https://www.youtube.com/watch?v=YN0jMyJR31M&list=PL4SIC1d_ab-aOxWPucn31NHkQvNPHK1D1&index=4 20:30

	return 0;
}