#include "LinkedList.h"

#include <iostream>

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// 데이터를 저장할 노드 생성
	tNode* pNode = (tNode*)malloc(sizeof(tNode)); // 이부분 아주 중요!
	// 데이터 복사
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// 추가한 데이터가 처음인지 아닌지
	if (0 == _pList->iCount)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// 현재 가장 마지막 노드를 찾아서,
		// 해당	노드의 pNext 를 생성시킨 노드의 주소로 채움
		tNode* pCurFinalNode = _pList->pHeadNode;
		while (true) // pCurFinalNode->pNextNode 을 True와 대체해서 간략가능
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
	// 과제
	// 연결리스트 PushFront 구현해보기
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
	// 재귀함수
	// Release(_pList->pHeadNode);

	// 반복문
	tNode* pDeleteNode = _pList->pHeadNode;

	while (pDeleteNode)
	{
		tNode* pNext = pDeleteNode->pNextNode;
		free(pDeleteNode);
		pDeleteNode = pNext;
	}
}
