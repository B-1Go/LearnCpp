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
	// pList는 main() 스택메모리에 있으므로 함수가 종료되면 알아서 메모리가 해제된다.
	tabNode* pTemp = m_pHeadNode;
	for (int i = 0; i < m_iCount - 1; ++i)
	{
		tabNode* Temp = pTemp;
		delete pTemp;
		pTemp = Temp->pNextNode;
	}
	m_iCount = 0;
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

void pList::psuh_insert(int _Idx, int _iData)
{
	// 1. 처음인지 아닌지 체크 or 현재 카운트보다 큰 인덱스인지 아닌지
	if (nullptr == m_pHeadNode || _Idx >= m_iCount)
	{
		push_back(_iData);
		return;
	}

	// 2. _Idx 노드 찾기
	tabNode* pTemp = m_pHeadNode;
	for (int i = 0; i < _Idx - 1; ++i)
	{
		tabNode* Temp = pTemp;
		pTemp = Temp->pNextNode;
	}

	// 3. 새로운 노드 생성해서 데이터 넣기
	tabNode* pIdxNode = new tabNode;
	pIdxNode->iData = _iData;
	pIdxNode->pNextNode = pTemp->pNextNode;
	pTemp->pNextNode = pIdxNode;

	// 4. 데이터 카운트 증가
	m_iCount++;
}
