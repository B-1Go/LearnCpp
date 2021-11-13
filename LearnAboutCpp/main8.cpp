#include <stdlib.h>
#include <stdio.h>

void Test(int* a)
{
	*a = 500;
}


int main()
{
	// ������ ����
	// �ڷ��� ������
	int* pInt = nullptr;

	// �ּҸ� ����
	
	char* pChar = nullptr;
	short* pShort = nullptr;

	// ������ ������ �ü�� ��Ʈ�� ���� �������̴�. 64��Ʈ(8����Ʈ) OS������ 8����Ʈ ������ ������ �ȴ�.
	int iSize = sizeof(int*);

	int i = 0;
	pInt = &i;

	// �ּҴ� 1����Ʈ�� �ο��ȴ�.
	// ���� pInt�� 100������� �ϸ� 4����Ʈ �̹Ƿ� ���� 104������ �ȴ�.

	pInt += 1;
	// ������ ������ +1�� �ܼ��� 100 + 1 = 101 �� �Ǵ°� �ƴ϶�
	// ������ ������ �ǹ��ϴ� ũ�⿡ ���� ������ �ǹ��Ѵ�.
	// ���� pInt�� +1�� �ϸ� 104���� ��, 4����Ʈ�� �����ϰ� �ȴ�.
	// ���� char�� +1�� �ϸ� 1����Ʈ��, long long�� �ϸ� 8����Ʈ�� ���� �Ѵ�.
	// ���� ������ ���� ������ �� �ڷ��� ũ�⿡ ���� �Դ� ���� �Ѵ�.

	// pInt �� int* ���� �̱� ������, ����Ű�� ���� int�� �ؼ��Ѵ�.
	// ���� �ּҰ��� 1 �����ϴ� �ǹ̴� ���� int ��ġ�� �����ϱ� ���ؼ� sizeof(int) ������	�����ϰ� �ȴ�.

	// �����Ϳ� �迭
	// �迭�� Ư¡
	// 1. �޸𸮰� �������� �����̴�.
	// 2. �迭�� �̸��� �迭�� ���� �ּ��̴�.
	int iArr[10] = {};

	// int ������ ���� *(�����ͺ�����)
	*(iArr) = 10; // int[0] = 10;
	*(iArr + 1) = 10; // int[1] = 10;

	// int(&iArr2)[10] = iArr; ��Ʈ �迭 �����Ͱ� ��Ȯ�� ǥ���ε� ���߿� ����



	// ������ ���� Ȯ�� ����
	// ���� 1.
	short sArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int* pI = (int*)sArr;

	int iData = *((short*)(pI + 2));

	printf("1�� ���� ���� : %d\n", iData); // 5


	// ���� 2.
	char cArr[2] = { 1, 1 };
	
	short* pS = (short*)cArr;

	iData = *pS;

	printf("2�� ���� ���� : %d\n", iData); // 257


	int a = 100;

	Test(&a);

	printf("��� : %d\n", a);
	// Test�Լ� �ȿ� a = 500; �־ main�Լ��� a�� �ٲ��� �ʴ´�. �ֳĸ� �����Լ��� ���������� ����ȣ��ǰ� ������� ���̱� �����̴�.
	// �׷��� ���� �޸𸮿� �ּҸ� �޾Ƽ� �����ϸ� ���� ������?
	// �׷��� Test �Լ��� main�Լ��� a������ �ּҸ� �޾Ƽ� �����ϴ� ����� �ִ�.

	scanf_s("%d", &a);
	// scanf_s�� �� &a�� �ؾߵǴ��� ���� ������ �� �ִ�.
	// �Է°��� �ּҸ� �Ѱ��༭ �ּ��� �����͸� �����Ͽ� �����ϴ� ���̴�.



	// const

	volatile const int cint = 100; // volatile(�ֹ߼�) : �������� ����ȭ �������� cint �޸� �ּҷ� ���� value�� ����Ȯ���ض�.

	// ���ȭ
	// r-value : ���
	// l-value : ����
	int ii = 10;
	// =�������� ������ left-value, �������� right-value���� ���� ����.

	pInt = (int*)&cint; // ���ȭ�� ��ٰ� ���ٲٴ°� �ƴϰ� C++���� ���������� �����ִ� �� ���̴�.
	*pInt = 300;
	printf("cint ��� : %d\n", cint);




	return 0;
}