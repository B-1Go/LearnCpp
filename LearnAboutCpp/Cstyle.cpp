#include "Cstyle.h"
#include <iostream>

void InitalArr(tCArr* _ptCArr)
{
	_ptCArr->pInt = (int*)malloc((sizeof(int) * 2));
	_ptCArr->iCount = 0;
	_ptCArr->iMax = 2;
}

void PushBack(tCArr* _ptCArr, int _iData)
{
	// 1. �迭�� ����� ����Ѱ�
	if (_ptCArr->iMax <= _ptCArr->iCount)
	{
		// �迭�� ����� �÷���
		// Resize(_ptCArr);
	}

	// 2. �����͸� �迭 �� ��°�� �ִ°�?
	_ptCArr->pInt[_ptCArr->iCount] = _iData;


	// 3. ������ ī��Ʈ ����
	_ptCArr->iCount++;
}

void ReleaseArr(tCArr* _ptCArr)
{
	free(_ptCArr->pInt);
	_ptCArr->iCount = 0;
	_ptCArr->iMax = 0;
}
