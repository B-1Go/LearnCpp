#pragma once

typedef struct _tabCArr
{
	int* pInt;
	int iCount;
	int iMax;
}tCArr;

// 초기화
void InitalArr(tCArr* _ptCArr);

// 데이터 재할당
void Resize(tCArr* _ptCArr); // 2배씩 증가
void Resize(tCArr* _ptCArr, int _iDataSizeof); // 원하는 만큼 증가 - 인자를 다르게 해서 동일한 함수명을 쓰는 것을 함수 오버라이딩 이라고 한다.

// 데이터 후삽입
void PushBack(tCArr* _ptCArr, int _iData);
// 데이터 원하는 곳에 삽입하기
void PushInsert(tCArr* _ptCArr, int _idx, int _iData);

// 데이터 머지시키기
void MergeArr(tCArr* _ptCArr1, tCArr* _ptCArr2); // 기본적으로는 _ptCArr1 뒤에 이어서 _ptCArr2가 붙는다.
void MergeArr(tCArr* _ptCArr1, tCArr* _ptCArr2, int _idx); // 원하는 중간에 삽입할 수 있게 구현한다.

// 데이터 원하는 곳에 데이터 삭제
void DeleteArr(tCArr* _ptCArr, int _idx);

// 데이터 버블 정렬
void BubbleSort(tCArr* _ptCArr);

// 해제
void ReleaseArr(tCArr* _ptCArr);