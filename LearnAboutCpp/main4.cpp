
# include <stdio.h>


// C��Ż�� ����ü
// ����ü�� ����� ���� �ڷ����� �� �� �ִ�.
typedef struct _tagMyST
{
	int a; // int a��� �ؼ� a�� ����ó�� ���̴µ� �ʰ� ������ [�ڷ���]�̱� ������
	float f; // a�� int�� �����ϴ� �̸��� �ǰ�, f�� float�� �����ϴ� �ڷ����� �ȴ�.
}MYST;

typedef struct _tagBig
{
	MYST k; // ���� �⺻ �ڷ����� ������ �� ū �ڷ����� ���� �� �ִ�.
	int i;
	char c;
}BIG;

typedef int INT; // typedef �� �ڷ����� �ƿ� ������ ���ִ� ����̴�.


// C++�� �̷��� ����ü�� �����ϰ� NewStruct��� �����Ͽ� ����� �� �ִµ�
// C������ �⺻�ڷ����� �ƴ� struct�� ���� �����ϱ� ������ struct NewStruct��� �����ؾ� ��� �� �� �ִ�.
// C �Ǵ� C++ ���� ���������� ��� �� �� �ְ� typedef�� ����Ͽ� �����ϸ� C������ ��� �� �� �ִ�.
struct NewStruct
{
	int a;
	short s;
};

// �Ʒ��� ���� NEWST�� �ڷ����� �����ϸ� C�� C++���� �� ��밡���ϴ�.
typedef struct NewStruct
{
	int a;
	short s;
}NEWST;





int main()
{
	int arr[10] = { 1, 2, 3, 4, 5 }; // �ʱ�ȭ ó�� ù��°���� ������� ���� �� ���� 0�� ����.

	// ����ü
	MYST t = { 100, 3.14f }; // ����ü�� �迭ó�� �ʱ�ȭ ó�� �� �ʱⰪ ������ �����ϴ�. ���� int a = 100, float f = 3.14f �� ���Եȴ�.
	t.a = 10; // t�ڷ����� ���������� �����ϴ� ���
	t.f = 10.314f;


	int iSize = sizeof(MYST);

	INT a; // typedef���� �⺻�ڷ��� int�� INT�� ���� ����� ������ �����Ϸ��� int�� �˾� ��´�.

	return 0;
};