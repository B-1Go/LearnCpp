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
void PushBackArr(tCArr* _ptCArr, int _iData);
// ������ ���ϴ� ���� �����ϱ�
void PushInsertArr(tCArr* _ptCArr, int _idx, int _iData);

// ������ ������Ű��
void MergeArr(tCArr* _ptCArr1, tCArr* _ptCArr2); // �⺻�����δ� _ptCArr1 �ڿ� �̾ _ptCArr2�� �ٴ´�.
void MergeArr(tCArr* _ptCArr1, tCArr* _ptCArr2, int _idx); // ���ϴ� �߰��� ������ �� �ְ� �����Ѵ�.

// ������ ���ϴ� ���� ������ ����
void DeleteArr(tCArr* _ptCArr, int _idx);

// ������ ���� ����
void BubbleSort(tCArr* _ptCArr);

// ����
void ReleaseArr(tCArr* _ptCArr);


//---------------------------------------------------------------------------------------------------------------------------------------------------


typedef struct _tabNode
{
	int iData;
	struct _tabNode* pNextNode;
}tNode;

typedef struct _tabList
{
	tNode* pHeadNode;
	int iCount;
}tList;


// ������ ����Ʈ �ʱ�ȭ
void InitalList(tList* _pList);

// ������ ����Ʈ ������ �߰�
void PushBackList(tList* _pList, int _iData);
void PushInsertList(tList* _pList, int _idx, int _iData);