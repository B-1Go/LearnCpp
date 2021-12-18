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

//-------------------------------------------------------------------------------------------------------------

pList::pList()
	: m_iCount(0)
	, m_pHeadNode(nullptr)
{
}

pList::~pList()
{
	//
}

void pList::push_back(int _iData)
{
	// 1. 처음인지 아닌지 검사
	if (nullptr == m_pHeadNode)
	{
		m_pHeadNode = new tabNode;
		m_pHeadNode->iData = _iData;
		m_pHeadNode->pNextNode = nullptr;
		m_iCount++;
		return;
	}

	// 2. 말단노드 찾기
	tabNode* pTemp = m_pHeadNode;
	for (int i = 0; i < m_iCount - 1; ++i)
	{
		tabNode* Temp = pTemp;
		pTemp = Temp->pNextNode;
	}
	
	// 3. 말단노드에 새로운 노드 만들고 이동하기
	pTemp->pNextNode = new tabNode;
	pTemp = pTemp->pNextNode;

	// 4. 새로만든 노드에 데이터 넣기
	pTemp->iData = _iData;
	pTemp->pNextNode = nullptr;
	
	// 5. 데이터 카운트 증가시키기
	m_iCount++;
}
