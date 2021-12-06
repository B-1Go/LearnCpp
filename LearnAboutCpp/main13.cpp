#include <iostream>

#include "LinkedList.h"

int main()
{
	tLinkedList list = {};
	InitList(&list);

	PushFront(&list, 400);
	PushBack(&list, 100);
	PushBack(&list, 200);
	PushBack(&list, 300);
	PushFront(&list, 1);

	tNode* pNode = list.pHeadNode;
	for (int i = 0; i < list.iCount; ++i)
	{
		printf("%d\n", pNode->iData);
		pNode = pNode->pNextNode;
	}

	ReleaseList(&list);

	return 0;
}

// Insert, Delete �� List�� �߰����� ����� �����ϸ� ���� ������ �ȴ�.

// ���ݱ����� C��Ÿ���� �ڷᱸ���� ����

// ������ Class��� ���� �̿��ؼ� �����迭�� List�� ������ ����

// C��Ÿ���� �ڷᱸ���� �� ����ϰ� �ִٰ� C++���� Class�� �����غ��鼭 ��� ���������� ���ϸ� ����