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

// Insert, Delete 등 List에 추가적인 기능을 구현하면 좋은 경험이 된다.

// 지금까지는 C스타일의 자료구조를 만듬

// 앞으로 Class라는 것을 이용해서 가변배열과 List를 구현할 예정

// C스타일의 자료구조를 잘 기억하고 있다가 C++에서 Class로 구현해보면서 어떻게 좋아졌는지 비교하면 좋음