#pragma once

// int
typedef struct _tabArr
{
	int* pInt;
	int iCount;
	int iMaxCount;

}tArr;


// �迭 �ʱ�ȭ �Լ�
void InitArr(tArr* _pArr);

// ������ �߰� �Լ�
void PushBack(tArr* _pArr, int _iData);

// ������ ���Ҵ��ϴ� �Լ�
// void Reallocate(tArr* _pArr);

// �迭 �޸� ���� �Լ�
void ReleaseArr(tArr* _pArr);

// ������ ���� �Լ�
void sort(tArr* _pArr);