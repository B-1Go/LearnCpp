#include <stdio.h>
#include <assert.h>
#include <iostream>

#include "Cstyle.h"

int main()
{
	tCArr arr = {};

	// �ʱ�ȭ
	InitalArr(&arr);

	// ������ �ֱ�
	PushBack(&arr, 10);

	// �޸� ����
	ReleaseArr(&arr);

	return 0;
}

// TODO
// 1. C��Ÿ�� �迭 ������ - Resize �����
// 2. Quest �����غ���