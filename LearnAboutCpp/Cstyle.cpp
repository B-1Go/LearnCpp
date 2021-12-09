#include "Cstyle.h"
#include <iostream>

void InitalArr(tCArr* _ptCArr)
{
	_ptCArr->pInt = (int*)malloc((sizeof(int) * 2));
	_ptCArr->iCount = 0;
	_ptCArr->iMax = 2;
}

void PushBack(tCArr* _ptCArr, int _iData)
{
	// 1. 배열의 사이즈가 충분한가
	if (_ptCArr->iMax <= _ptCArr->iCount)
	{
		// 배열의 사이즈를 늘려라
		// Resize(_ptCArr);
	}

	// 2. 데이터를 배열 몇 번째에 넣는가?
	_ptCArr->pInt[_ptCArr->iCount] = _iData;


	// 3. 데이터 카운트 증가
	_ptCArr->iCount++;
}

void ReleaseArr(tCArr* _ptCArr)
{
	free(_ptCArr->pInt);
	_ptCArr->iCount = 0;
	_ptCArr->iMax = 0;
}
