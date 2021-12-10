#pragma once

typedef struct _tabCArr
{
	int* pInt;
	int iCount;
	int iMax;
}tCArr;

// �ʱ�ȭ
void InitalArr(tCArr* _ptCArr);

// ������ ���Ҵ�
void Resize(tCArr* _ptCArr); // 2�辿 ����
void Resize(tCArr* _ptCArr, int _iDataSizeof); // ���ϴ� ��ŭ ���� - ���ڸ� �ٸ��� �ؼ� ������ �Լ����� ���� ���� �Լ� �������̵� �̶�� �Ѵ�.

// ������ �Ļ���
void PushBack(tCArr* _ptCArr, int _iData);
// ������ ���ϴ� ���� �����ϱ�
void PushInsert(tCArr* _ptCArr, int _idx, int _iData);

// ������ ������Ű��
void MergeArr(tCArr* _ptCArr1, tCArr* _ptCArr2); // �⺻�����δ� _ptCArr1 �ڿ� �̾ _ptCArr2�� �ٴ´�.
void MergeArr(tCArr* _ptCArr1, tCArr* _ptCArr2, int _idx); // ���ϴ� �߰��� ������ �� �ְ� �����Ѵ�.

// ������ ���ϴ� ���� ������ ����
void DeleteArr(tCArr* _ptCArr, int _idx);

// ������ ���� ����
void BubbleSort(tCArr* _ptCArr);

// ����
void ReleaseArr(tCArr* _ptCArr);