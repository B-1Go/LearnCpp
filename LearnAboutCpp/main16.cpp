#include <iostream>

#include "CList.h"


int main()
{
	CList<float> list;

	for (int i = 0; i < 4; i++)
	{
		list.push_back(i);
	}


	CList<int> ilist;

	for (int i = 0; i < 4; i++)
	{
		ilist.push_back(i);
	}

	// C printf
	std::cout << "¾È³ç" << 10 << std::endl;


	// C scanf
	int iInput = 0;
	std::cin >> iInput;

	return 0;
}