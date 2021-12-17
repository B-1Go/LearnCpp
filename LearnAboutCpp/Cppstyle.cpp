#include <iostream>
#include <assert.h>
#include "Cppstyle.h"

pCArr::pCArr()
	: m_iCount(0)
	, m_pInt(nullptr)
	, m_iMax(2)
{
	m_pInt = new int[2]; // m_pInt = (int*)malloc(sizeof(int) * 2); 이거와 같은 의미
}

pCArr::~pCArr()
{
	delete[] m_pInt;
}

void pCArr::push_back(int _iData)
{
	if (m_iCount >= m_iMax)
	{
		resize(m_iMax * 2);
	}
	m_pInt[m_iCount] = _iData;
	m_iCount++;
}

void pCArr::push_insert(int _idx, int _iData)
{
	if (m_iCount >= m_iMax)
	{
		resize(m_iMax * 2);
	}

	if (_idx >= m_iCount)
	{
		push_back(_iData);
		return;
	}

	for (int i = m_iCount; i >= _idx; --i)
	{
		m_pInt[i + 1] = m_pInt[i];
	}
	m_pInt[_idx] = _iData;
	m_iCount++;
}

void pCArr::resize(int _iResizeValue)
{
	if (m_iMax >= _iResizeValue)
	{
		assert(nullptr);
	}

	int* m_Temp = new int[_iResizeValue];
	for (int i = 0; i < m_iCount; ++i)
	{
		m_Temp[i] = m_pInt[i];
	}

	delete[] m_pInt;
	m_pInt = m_Temp;
	m_iMax = _iResizeValue;
}

void pCArr::show_data()
{
	for (int i = 0; i < m_iCount; ++i)
	{
		printf("%d: %d\n", i, m_pInt[i]);
	}
}
