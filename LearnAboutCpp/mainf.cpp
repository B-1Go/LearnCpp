#include "Arrf.h"
#include <stdio.h>
#include <iostream>


int main()
{
	tArrf tf;

	// �ʱ�ȭ
	InitArrf(&tf);

	// �� ����ֱ�
	for (int i = 0; i < 10; ++i)
	{
		float f = i + 0.1;
		PushBack(&tf, f);
	}

	for (int i = 0; i < tf.iCount; ++i)
	{
		printf("%f\n", tf.pfloat[i]);
	}

	// �޸� ����
	ReleaseArrf(&tf);

	return 0;
}