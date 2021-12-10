#include "Cstyle.h"
#include <iostream>
#include <assert.h>

void InitalArr(tCArr* _ptCArr)
{
	_ptCArr->pInt = (int*)malloc((sizeof(int) * 2));
	_ptCArr->iCount = 0;
	_ptCArr->iMax = 2;
}

void Resize(tCArr* _ptCArr)
{
	// 1. ���ο� �� �޸� �Ҵ�
	int* pTemp = (int*)malloc((sizeof(int)) * _ptCArr->iMax * 2);

	// 2. �����͸� �������� ���ο� ������ �ű��
	for (int i = 0; i < _ptCArr->iCount; ++i)
	{
		pTemp[i] = _ptCArr->pInt[i];
	}

	// 3. ���� �޸� ����
	free(_ptCArr->pInt);

	// 4. ���ο� �޸� �ּ� ����
	_ptCArr->pInt = pTemp;

	// 5. ���ο� �޸� ũ�Ⱚ ����
	_ptCArr->iMax *= 2;
}

void Resize(tCArr* _ptCArr, int _iDataSizeof)
{
	// 0. ���� ũ�⺸�� �۰ų� ���� ���� ��� ���
	if (_iDataSizeof <= _ptCArr->iMax)
	{
		assert(nullptr);
	}

	// 1. ���ο� �� �޸� �Ҵ�
	int* pTemp = (int*)malloc((sizeof(int)) * _iDataSizeof);

	// 2. �����͸� �������� ���ο� ������ �ű��
	for (int i = 0; i < _ptCArr->iCount; ++i)
	{
		pTemp[i] = _ptCArr->pInt[i];
	}

	// 3. ���� �޸� ����
	free(_ptCArr->pInt);

	// 4. ���ο� �޸� �ּ� ����
	_ptCArr->pInt = pTemp;

	// 5. ���ο� �޸� ũ�Ⱚ ����
	_ptCArr->iMax = _iDataSizeof;
}

void PushBack(tCArr* _ptCArr, int _iData)
{
	// 1. �迭�� ����� ����Ѱ�
	if (_ptCArr->iMax <= _ptCArr->iCount)
	{
		// �迭�� ����� �÷���
		Resize(_ptCArr);
	}

	// 2. �����͸� �迭 �� ��°�� �ִ°�?
	_ptCArr->pInt[_ptCArr->iCount] = _iData;


	// 3. ������ ī��Ʈ ����
	_ptCArr->iCount++;
}

void PushInsert(tCArr* _ptCArr, int _idx, int _iData)
{
	// 1. �迭 �߰��� ����, ���� �ǵ� �̻��� �ε����� �ְԵǸ� PushBack �� �̷������ ��
	if (_idx >= _ptCArr->iCount)
	{
		PushBack(_ptCArr, _iData);
		return;
	}

	// 2. �迭�� ����� ����Ѱ�?
	if (_ptCArr->iMax <= _ptCArr->iCount)
	{
		// �迭�� ����� �÷���
		Resize(_ptCArr);
	}
	
	// 3. �����͸� �ֱ� ���� �ش� �ε������� �ڷ� ��ĭ�� �̵�
	for (int i = _ptCArr->iCount; i > _idx; --i)
	{
		_ptCArr->pInt[i] = _ptCArr->pInt[i - 1];
	}

	// 4. ������ �ֱ�
	_ptCArr->pInt[_idx] = _iData;
	

	// 5. ������ ī��Ʈ ����
	_ptCArr->iCount++;
}

void DeleteArr(tCArr* _ptCArr, int _idx)
{
	// 0. �����Ͱ� ���� �κ��̸� ���
	if (_idx >= _ptCArr->iCount)
	{
		assert(nullptr);
	}
	
	// 1. �ش� ��ġ���� �ڿ��� ��ĭ�� ����
	for (int i = _idx; i < _ptCArr->iCount; i++)
	{
		_ptCArr->pInt[i] = _ptCArr->pInt[i + 1];
	}

	// 2. ������ ī��Ʈ ����
	_ptCArr->iCount--;
}

void BubbleSort(tCArr* _ptCArr)
{
	bool pChk = true;
	int pTemp;
	while (pChk)
	{
		pChk = false;
		for (int i = 0; i < _ptCArr->iCount - 1; ++i)
		{
			if (_ptCArr->pInt[i] > _ptCArr->pInt[i + 1])
			{
				pTemp = _ptCArr->pInt[i];
				_ptCArr->pInt[i] = _ptCArr->pInt[i + 1];
				_ptCArr->pInt[i + 1] = pTemp;
				pChk = true;
			}
		}
	}
}

void ReleaseArr(tCArr* _ptCArr)
{
	free(_ptCArr->pInt);
	_ptCArr->iCount = 0;
	_ptCArr->iMax = 0;
}

void MergeArr(tCArr* _ptCArr1, tCArr* _ptCArr2)
{
	// 1. �迭1�� �迭2�� �� ������ �� �ִ±�? �迭ũ�Ⱑ �Ǵ°�?
	if (_ptCArr1->iMax <= _ptCArr1->iCount + _ptCArr2->iCount)
	{
		Resize(_ptCArr1, _ptCArr1->iCount + _ptCArr2->iCount + 10);
	}

	// 2. �迭1 �ڿ� �迭2 ������ ���̱�
	for (int i = 0; i < _ptCArr2->iCount; ++i)
	{
		_ptCArr1->pInt[i + _ptCArr1->iCount] = _ptCArr2->pInt[i];
	}

	// 3. ������ ī��Ʈ ����
	_ptCArr1->iCount = _ptCArr1->iCount + _ptCArr2->iCount;

	// 4. ������ ũ�� ����
	_ptCArr1->iMax = _ptCArr1->iCount + _ptCArr2->iCount + 10;
}

void MergeArr(tCArr* _ptCArr1, tCArr* _ptCArr2, int _idx)
{

}