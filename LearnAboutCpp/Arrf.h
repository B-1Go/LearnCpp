#pragma once

typedef struct _tagArrf
{
	float* pfloat;
	int iCount;
	int iMaxSize;
}tArrf;

// 초기화
void InitArrf(tArrf* _pArrf);

// 값넣기
void PushBack(tArrf* _pArrf, float _pFloat);

// 메모리 해제 함수
void ReleaseArrf(tArrf* _pArrf);