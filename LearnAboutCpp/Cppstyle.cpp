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
}

void pCArr::resize(int _iResizeValue)
{
}
