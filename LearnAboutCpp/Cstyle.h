#pragma once

typedef struct _tabCArr
{
	int* pInt;
	int iCount;
	int iMax;
}tCArr;

// �ʱ�ȭ
void InitalArr(tCArr* _ptCArr);

// ������ ����
void PushBack(tCArr* _ptCArr, int _iData);

// ����
void ReleaseArr(tCArr* _ptCArr);