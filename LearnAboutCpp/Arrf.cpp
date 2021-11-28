#include <iostream>

#include "Arrf.h"

void InitArrf(tArrf* _pArrf)
{
	(*_pArrf).iMaxSize = 2; // ���: _pArrf->iMaxSize = 2;
	(*_pArrf).iCount = 0;
	(*_pArrf).pfloat = (float*)malloc(sizeof(float) * (*_pArrf).iMaxSize);
}

void Realloacte(tArrf* _pArrf)
{
	// 1. �� Ŀ�� �޸� �����
	float* temp = (float*)malloc(sizeof(float) * _pArrf->iMaxSize * 2);

	// 2. ���������� �Ű��ֱ�
	for (int i = 0; i < _pArrf->iCount; ++i)
	{
		temp[i] = _pArrf->pfloat[i];
	}

	// 3. ���� �޸� ����
	free(_pArrf->pfloat);

	// 4. ���ο� �޸� �Ҵ�
	_pArrf->pfloat = temp;

	// 5. iMaxSize ����
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
