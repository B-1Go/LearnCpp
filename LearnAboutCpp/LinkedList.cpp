#include "LinkedList.h"

#include <iostream>

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// �����͸� ������ ��� ����
	tNode* pNode = (tNode*)malloc(sizeof(tNode)); // �̺κ� ���� �߿�!
	// ������ ����
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// �߰��� �����Ͱ� ó������ �ƴ���
	if (0 == _pList->iCount)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// ���� ���� ������ ��带 ã�Ƽ�,
		// �ش�	����� pNext �� ������Ų ����� �ּҷ� ä��
		tNode* pCurFinalNode = _pList->pHeadNode;
		while (true) // pCurFinalNode->pNextNode �� True�� ��ü�ؼ� ��������
		{
			if (nullptr == pCurFinalNode->pNextNode)
			{
				break;
			}

			pCurFinalNode = pCurFinalNode->pNextNode;
		}

		pCurFinalNode->pNextNode = pNode;
	}

	++_pList->iCount;
}

void PushFront(tLinkedList* _pList, int _iData)
{
	// ����
	// ���Ḯ��Ʈ PushFront �����غ���
}

void Release(tNode* _pNode)
{
	if (nullptr == _pNode)
		return;

	Release(_pNode->pNextNode);

	free(_pNode);
}


void ReleaseList(tLinkedList* _pList)
{
	// ����Լ�
	// Release(_pList->pHeadNode);

	// �ݺ���
	tNode* pDeleteNode = _pList->pHeadNode;

	while (pDeleteNode)
	{
		tNode* pNext = pDeleteNode->pNextNode;
		free(pDeleteNode);
		pDeleteNode = pNext;
	}
}
