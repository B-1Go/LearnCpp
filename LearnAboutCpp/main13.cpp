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

	ReleaseList(&list);

	return 0;
}