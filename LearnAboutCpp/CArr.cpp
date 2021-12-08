#include "CArr.h"

#include <assert.h>

CArr::CArr()
	: m_pInt(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pInt = new int[2]; // 기존의 C에서는 malloc으로 동적할당을 했다면 C++에서는 new 라는 키워드로 동적할당을 한다.
}

CArr::~CArr()
{
	delete[] m_pInt; // 기존의 C에서는 free라는 함수를 사용했다면 C++에서는 delete라를 사용한다. int[2] 배열의 동적할당은 delete[] 로 작성한다.
}

void CArr::push_back(int _Data)
{
	// 힙 영역에 할당한 공간이 다 참
	if (m_iMaxCount <= m_iCount)
	{
		// 재할당
		resize(m_iMaxCount * 2);
	}

	// 데이터 추가
	m_pInt[m_iCount++] = _Data;
}

void CArr::resize(int _iResizeCount)
{
	// 현재	최대 수용량 보다 더 적은 수치로 확장하려는 경우
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. 리사이즈 시킬 
	int* pNew = new int[_iResizeCount];

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pInt[i];
	}

	// 3. 기존 공간은 메모리 해제
	delete[] m_pInt;

	// 4. 배열이 새로 할당된 공간을 가르키게 한다.
	m_pInt = pNew;

	// 5. MaxCount 변경점 적용
	m_iMaxCount = _iResizeCount;
}

int& CArr::operator[](int idx)
{
	return m_pInt[idx];
}
