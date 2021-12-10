#include "Cstyle.h"
#include <iostream>
#include <assert.h>

void InitalArr(tCArr* _ptCArr)
{
	_ptCArr->pInt = (int*)malloc((sizeof(int) * 2));
	_ptCArr->iCount = 0;
	_ptCArr->iMax = 2;
}

void Resize(tCArr* _ptCArr)
{
	// 1. 새로운 힙 메모리 할당
	int* pTemp = (int*)malloc((sizeof(int)) * _ptCArr->iMax * 2);

	// 2. 데이터를 기존에서 새로운 공간을 옮기기
	for (int i = 0; i < _ptCArr->iCount; ++i)
	{
		pTemp[i] = _ptCArr->pInt[i];
	}

	// 3. 기존 메모리 해제
	free(_ptCArr->pInt);

	// 4. 새로운 메모리 주소 지정
	_ptCArr->pInt = pTemp;

	// 5. 새로운 메모리 크기값 적용
	_ptCArr->iMax *= 2;
}

void Resize(tCArr* _ptCArr, int _iDataSizeof)
{
	// 0. 현재 크기보다 작거나 같을 값일 경우 경고문
	if (_iDataSizeof <= _ptCArr->iMax)
	{
		assert(nullptr);
	}

	// 1. 새로운 힙 메모리 할당
	int* pTemp = (int*)malloc((sizeof(int)) * _iDataSizeof);

	// 2. 데이터를 기존에서 새로운 공간을 옮기기
	for (int i = 0; i < _ptCArr->iCount; ++i)
	{
		pTemp[i] = _ptCArr->pInt[i];
	}

	// 3. 기존 메모리 해제
	free(_ptCArr->pInt);

	// 4. 새로운 메모리 주소 지정
	_ptCArr->pInt = pTemp;

	// 5. 새로운 메모리 크기값 적용
	_ptCArr->iMax = _iDataSizeof;
}

void PushBack(tCArr* _ptCArr, int _iData)
{
	// 1. 배열의 사이즈가 충분한가
	if (_ptCArr->iMax <= _ptCArr->iCount)
	{
		// 배열의 사이즈를 늘려라
		Resize(_ptCArr);
	}

	// 2. 데이터를 배열 몇 번째에 넣는가?
	_ptCArr->pInt[_ptCArr->iCount] = _iData;


	// 3. 데이터 카운트 증가
	_ptCArr->iCount++;
}

void PushInsert(tCArr* _ptCArr, int _idx, int _iData)
{
	// 1. 배열 중간에 삽입, 만약 맨뒤 이상의 인덱스에 넣게되면 PushBack 이 이루어지게 함
	if (_idx >= _ptCArr->iCount)
	{
		PushBack(_ptCArr, _iData);
		return;
	}

	// 2. 배열의 사이즈가 충분한가?
	if (_ptCArr->iMax <= _ptCArr->iCount)
	{
		// 배열의 사이즈를 늘려라
		Resize(_ptCArr);
	}
	
	// 3. 데이터를 넣기 위해 해당 인덱스부터 뒤로 한칸씩 이동
	for (int i = _ptCArr->iCount; i > _idx; --i)
	{
		_ptCArr->pInt[i] = _ptCArr->pInt[i - 1];
	}

	// 4. 데이터 넣기
	_ptCArr->pInt[_idx] = _iData;
	

	// 5. 데이터 카운트 증가
	_ptCArr->iCount++;
}

void DeleteArr(tCArr* _ptCArr, int _idx)
{
	// 0. 데이터가 없는 부분이면 경고문
	if (_idx >= _ptCArr->iCount)
	{
		assert(nullptr);
	}
	
	// 1. 해당 위치부터 뒤에서 한칸씩 당기기
	for (int i = _idx; i < _ptCArr->iCount; i++)
	{
		_ptCArr->pInt[i] = _ptCArr->pInt[i + 1];
	}

	// 2. 데이터 카운트 감소
	_ptCArr->iCount--;
}

void BubbleSort(tCArr* _ptCArr)
{
	bool pChk = true;
	int pTemp;
	while (pChk)
	{
		pChk = false;
		for (int i = 0; i < _ptCArr->iCount - 1; ++i)
		{
			if (_ptCArr->pInt[i] > _ptCArr->pInt[i + 1])
			{
				pTemp = _ptCArr->pInt[i];
				_ptCArr->pInt[i] = _ptCArr->pInt[i + 1];
				_ptCArr->pInt[i + 1] = pTemp;
				pChk = true;
			}
		}
	}
}

void ReleaseArr(tCArr* _ptCArr)
{
	free(_ptCArr->pInt);
	_ptCArr->iCount = 0;
	_ptCArr->iMax = 0;
}

void MergeArr(tCArr* _ptCArr1, tCArr* _ptCArr2)
{
	// 1. 배열1이 배열2를 다 수용할 수 있는기? 배열크기가 되는가?
	if (_ptCArr1->iMax <= _ptCArr1->iCount + _ptCArr2->iCount)
	{
		Resize(_ptCArr1, _ptCArr1->iCount + _ptCArr2->iCount + 10);
	}

	// 2. 배열1 뒤에 배열2 데이터 붙이기
	for (int i = 0; i < _ptCArr2->iCount; ++i)
	{
		_ptCArr1->pInt[i + _ptCArr1->iCount] = _ptCArr2->pInt[i];
	}

	// 3. 데이터 카운트 수정
	_ptCArr1->iCount = _ptCArr1->iCount + _ptCArr2->iCount;

	// 4. 데이터 크기 수정
	_ptCArr1->iMax = _ptCArr1->iCount + _ptCArr2->iCount + 10;
}

void MergeArr(tCArr* _ptCArr1, tCArr* _ptCArr2, int _idx)
{

}