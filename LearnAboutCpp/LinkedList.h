#pragma once


typedef struct _tagNode
{
	int iData;
	tNode* pNextNode;
}tNode;

typedef struct _tagList
{
	tNode* pHeadNode;
	int icount;
}tLinkedList;

// 초기화


// 데이터 넣기


// 메모리 해제