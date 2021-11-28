#include <iostream>

#include "Arrf.h"

void InitArrf(tArrf* _pArrf)
{
	(*_pArrf).iMaxSize = 2; // 축약: _pArrf->iMaxSize = 2;
	(*_pArrf).iCount = 0;
	(*_pArrf).pfloat = (float*)malloc(sizeof(float) * (*_pArrf).iMaxSize);
}

void Realloacte(tArrf* _pArrf)
{
	// 1. 더 커진 메모리 만들기
	float* temp = (float*)malloc(sizeof(float) * _pArrf->iMaxSize * 2);

	// 2. 기존데이터 옮겨주기
	for (int i = 0; i < _pArrf->iCount; ++i)
	{
		temp[i] = _pArrf->pfloat[i];
	}

	// 3. 기존 메모리 해제
	free(_pArrf->pfloat);

	// 4. 새로운 메모리 할당
	_pArrf->pfloat = temp;

	// 5. iMaxSize 갱신
	_pArrf->iMaxSize *= 2;
}

void PushBack(tArrf* _pArrf, float _iData)
{
	if (_pArrf->iCount >= _pArrf->iMaxSize)
	{
		Realloacte(_pArrf);
	}

	_pArrf->pfloat[_pArrf->iCount++] = _iData;
}

void ReleaseArrf(tArrf* _pArrf)
{
	free(_pArrf);
	_pArrf->iCount = 0;
	_pArrf->iMaxSize = 0;
}
