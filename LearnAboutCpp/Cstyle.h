#pragma once

typedef struct _tabCArr
{
	int* pInt;
	int iCount;
	int iMax;
}tCArr;

// 초기화
void InitalArr(tCArr* _ptCArr);

// 데이터 삽입
void PushBack(tCArr* _ptCArr, int _iData);

// 해제
void ReleaseArr(tCArr* _ptCArr);