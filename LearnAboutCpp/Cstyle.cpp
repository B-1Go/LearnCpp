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

void PushBackArr(tCArr* _ptCArr, int _iData)
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

void PushInsertArr(tCArr* _ptCArr, int _idx, int _iData)
{
	// 음수는 예외 처리
	if (_idx < 0)
	{
		assert(nullptr);
	}

	// 1. 배열 중간에 삽입, 만약 맨뒤 이상의 인덱스에 넣게되면 PushBack 이 이루어지게 함
	if (_idx >= _ptCArr->iCount)
	{
		PushBackArr(_ptCArr, _iData);
		return;
	}

	// 2. 배열의 사이즈가 충분한가?
	if (_ptCArr->iMax <= _ptCArr->iCount)
	{
		// 배열의 사이즈를 늘려라
		Resize(_ptCArr);
	}
	
	// 3. 데이터를 넣기 위해 맨뒤부터 해당인데스까지 한칸씩 뒤로 이동
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
	// 음수는 예외 처리
	if (_idx < 0)
	{
		assert(nullptr);
	}

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
	// 1. 배열1이 배열2를 다 수용할 수 있는가? 배열크기가 되는가?
	if (_ptCArr1->iMax <= _ptCArr1->iCount + _ptCArr2->iCount)
	{
		Resize(_ptCArr1, _ptCArr1->iCount + _ptCArr2->iCount + 10);

		// 데이터 크기 수정
		_ptCArr1->iMax = _ptCArr1->iCount + _ptCArr2->iCount + 10;
	}

	// 2. 배열1 뒤에 배열2 데이터 붙이기
	for (int i = 0; i < _ptCArr2->iCount; ++i)
	{
		_ptCArr1->pInt[i + _ptCArr1->iCount] = _ptCArr2->pInt[i];
	}

	// 3. 데이터 카운트 수정
	_ptCArr1->iCount = _ptCArr1->iCount + _ptCArr2->iCount;

	// 4. _ptCArr2 메모리 헤제
	ReleaseArr(_ptCArr2);
}

void MergeArr(tCArr* _ptCArr1, tCArr* _ptCArr2, int _idx)
{
	// 음수는 예외 처리
	if (_idx < 0)
	{
		assert(nullptr);
	}

	// 1. 배열1이 배열2를 다 수용할 수 있는가? 배열크기가 되는가?
	if (_ptCArr1->iMax <= _ptCArr1->iCount + _ptCArr2->iCount)
	{
		Resize(_ptCArr1, _ptCArr1->iCount + _ptCArr2->iCount + 10);

		// 데이터 크기 수정
		_ptCArr1->iMax = _ptCArr1->iCount + _ptCArr2->iCount + 10;
	}

	// 2. 데이터를 넣기 위해 맨뒤부터 해당인데스까지 배열2 데이터크기 만큼 뒤로 이동
	for (int i = _ptCArr1->iCount; i > _idx; --i)
	{
		_ptCArr1->pInt[i + _ptCArr2->iCount] = _ptCArr1->pInt[i - 1];
	}

	// 3. 배열1에 해당 위치부터 배열2 데이터 넣기
	for (int i = 0; i < _ptCArr2->iCount; ++i)
	{
		_ptCArr1->pInt[i + _idx] = _ptCArr2->pInt[i];
	}

	// 4. 데이터 카운트 수정
	_ptCArr1->iCount = _ptCArr1->iCount + _ptCArr2->iCount;

	// 5. 배열2 메모리 해제
	ReleaseArr(_ptCArr2);
}



//---------------------------------------------------------------------------------------------------------------------------------------------------


void InitalList(tList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBackList(tList* _pList, int _iData)
{
	// 데이터 저장할 노드 생성
	tNode* pNode = (tNode*)malloc(sizeof(tNode));

	// 데이터 복사
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// 처음인지 아닌지 확인
	if (nullptr == _pList->pHeadNode)
	{
		_pList->pHeadNode = pNode;
		++_pList->iCount;
		return;
	}
	
	// 말단 노드를 찾아서 데이터 추가
	tNode* pCurNode = _pList->pHeadNode;
	while(pCurNode->pNextNode)
	{
		pCurNode = pCurNode->pNextNode;
	}
	pCurNode->pNextNode = pNode;
	++_pList->iCount;
}

void PushInsertList(tList* _pList, int _idx, int _iData)
{
	// 음수는 예외 처리
	if (_idx < 0)
	{
		assert(nullptr);
	}

	// 들어있는 데이터보다 높은 인덱스는 푸쉬백 처리한다.
	if (_idx >= _pList->iCount)
	{
		PushBackList(_pList, _iData);
		return;
	}

	// 데이터 저장할 노드 생성
	tNode* pNode = (tNode*)malloc(sizeof(tNode));

	// 데이터 복사
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// 처음인지 아닌지 확인
	if (nullptr == _pList->pHeadNode)
	{
		_pList->pHeadNode = pNode;
		++_pList->iCount;
		return;
	}

	// 해당 인덱스까지 반복한다음 삽입해준다.
	tNode* pCurNode = _pList->pHeadNode; // List에서 노드로 참조를 함 따라서 _idx - 1 보정을 해줘야함
	for (int i = 0; i < _idx - 1; ++i)
	{
		pCurNode = pCurNode->pNextNode;
	}
	pNode->pNextNode = pCurNode->pNextNode;
	pCurNode->pNextNode = pNode;
	++_pList->iCount;
}

void ReleaseList(tList* _pList)
{

}