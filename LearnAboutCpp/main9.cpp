#include <stdlib.h>
#include <stdio.h>

int main()
{
	// const
	const int i = 100;

	// const�� ������
	int a = 0;
	int* pInt = &a;

	*pInt = 1;
	pInt = nullptr;

	// const ������
	const int* pConstInt = &a; // �����ͷ� �����ϴ� a ������ ���ó�� ��޵ȴ�. �������� ����� �����ϴ� ���̴�.
	// *pConstInt = 100;

	int b = 0;
	pConstInt = &b;


	// ������ const 
	int* const pIntConst = &a; // pIntConst ������ ������ ���ȭ ��
	*pIntConst = 100;
	// pIntConst = &b;

	// �ʱ�ȭ �� ����Ų ��� ����Ŵ, ����Ű�� ������ ���� �� �� ����
	const int* const pConstIntConst = nullptr; // 2���� ���ÿ� ���밡��


	// �̷��� ���� ����� ���� ���µ� �� 1�� �ôٴ� ����
	int const* p = &a; // const�� *�ڿ� �����Ƿ� �����ͷ� �����ϴ� a������ ���ó�� ��޵ȴ�. *�� �ش� �ּ��� ������ ����Ű�Ƿ� a ������ ����� �ȴ�.
	//*p = 1;


	{
		// ���ǻ���!
		int a = 0;
		const int* pInt = &a; // const�� �ٿ��ٰ� a���� ��ü�� ���ȭ�� �Ǵ� ���� �ƴϴ�. ���� �����Ͱ� a�ּ� ���� ������ �� ���ó�� ��޵ǰ� �ϰ� ���� ���̴�.
		// ��, �������� ���忡�� a������ const�� ���̴�.
		
		// *pInt = 100;
		a = 100; // ����ó�� a ��ü�� int a �̹Ƿ� ������ �����ϴ�.

		int* p = &a;
		*p = 100;
	}



	return 0;
}