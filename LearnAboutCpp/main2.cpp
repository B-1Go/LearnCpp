#include <stdio.h>

int Add(int a, int b)
{
	return a + b;
}



//�Լ�
int main()
{
	int Data = Add(100, 200);

	// �ݺ���
	// for()
	//for (/*�ݺ��� �ʱ�ȭ(����� �ѹ��� �����)*/ ; /*�ݺ��� ���� üũ(��,����)*/ ; /*�ݺ��� ����*/)
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
		// �̰� ������ �Ʒ� �ڵ带 �������� �ʰ� �������� �Ѿ��

		//break;
		// �̰� ������ for���� ������.
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

	return 0;
}