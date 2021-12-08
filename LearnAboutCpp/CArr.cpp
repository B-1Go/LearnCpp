#include "CArr.h"

#include <assert.h>

CArr::CArr()
	: m_pInt(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pInt = new int[2]; // ������ C������ malloc���� �����Ҵ��� �ߴٸ� C++������ new ��� Ű����� �����Ҵ��� �Ѵ�.
}

CArr::~CArr()
{
	delete[] m_pInt; // ������ C������ free��� �Լ��� ����ߴٸ� C++������ delete�� ����Ѵ�. int[2] �迭�� �����Ҵ��� delete[] �� �ۼ��Ѵ�.
}

void CArr::push_back(int _Data)
{
	// �� ������ �Ҵ��� ������ �� ��
	if (m_iMaxCount <= m_iCount)
	{
		// ���Ҵ�
		resize(m_iMaxCount * 2);
	}

	// ������ �߰�
	m_pInt[m_iCount++] = _Data;
}

void CArr::resize(int _iResizeCount)
{
	// ����	�ִ� ���뷮 ���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. �������� ��ų 
	int* pNew = new int[_iResizeCount];

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� �����Ų��.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pInt[i];
	}

	// 3. ���� ������ �޸� ����
	delete[] m_pInt;

	// 4. �迭�� ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	m_pInt = pNew;

	// 5. MaxCount ������ ����
	m_iMaxCount = _iResizeCount;
}

int& CArr::operator[](int idx)
{
	return m_pInt[idx];
}
