#pragma once

typedef struct _tagArrf
{
	float* pfloat;
	int iCount;
	int iMaxSize;
}tArrf;

// �ʱ�ȭ
void InitArrf(tArrf* _pArrf);

// ���ֱ�
void PushBack(tArrf* _pArrf, float _pFloat);

// �޸� ���� �Լ�
void ReleaseArrf(tArrf* _pArrf);