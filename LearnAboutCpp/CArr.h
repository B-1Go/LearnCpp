#pragma once

#include <assert.h>

template<typename T>
class CArr
{
private:
	T* m_pData;
	int m_iCount;
	int m_iMaxCount;

public:
	void push_back(const T& _Data); // Push_back 함수에 데이터 복사가 비효율적이여서 참조 하는 방식으로 바꿈
	void resize(int _iResizeCount);
	T* data() { return m_pData; }
	int size() { return m_iCount; }
	int capacity() { return m_iMaxCount; }
	T& operator[] (int idx); //레퍼런스

	class iterator; // 전방 선언
	iterator begin();
	iterator end();

public:
	// 생성자
	CArr();
	// 소멸자
	~CArr();

	// inner 클래스를 포함하고있는 클래스의 private 멤버에 접근 가능
	class iterator
	{
	private:
		CArr* m_pArr; // iterator가 가리킬 데이터를 관리하는 가변배열 주소
		T* m_pData; // 데이터들의 시작 주소
		int m_iIdx; // 가리키는 데이터의 인덱스

	public:
		T& operator* ()
		{
			// iterator가 알고있는 주소와, 가변배열이 알고 있는 주소가 달라진 경우(공간 확장으로 주소가 달라진 경우)
			// iterator가 end iterator 인 경우
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
			{
				assert(nullptr);
			}

			return m_pData[m_iIdx];
		}

		// 전위
		iterator& operator ++()
		{
			// 2. end iterator 인 경우
			// 3. iterator가 알고있는 주소와, 가변배열이 알고 있는 주소가 달라진 경우(공간 확장으로 주소가 달라진 경우)
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
			{
				assert(nullptr);
			}

			// 1. iterator가 마지막 데이터를 가리키고 있는 경우
			// --> end iterator가 된다.
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}

			return *this;
		}

		// ++ 후위 -> 실제로는 전위처럼 만나자 마자 후위연산이 호출되지만, 마지막에 연산되는 것 처럼 구현하는 것이다.
		iterator operator ++(int) // 복사본하고, 아무상관없는 int를 넣어주면 컴파일러가 후위연산자로 판단한다.
		{
			iterator copy_iter = *this; // 복사생성자로 알아서 컴파일러에 의해서 처리됨

			+= (*this);

			return copy_iter;
		}

		// -- 전위, 후위 직접 구현해보자
		iterator& operator --()
		{

			return *this;
		}
		
		// 비교연산자 ==, !=
		bool operator == (const iterator& _otheriter)
		{
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return true;
			}

			return false;
		}

		bool operator != (const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
		{

		}

		iterator(CArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
		{

		}

		~iterator()
		{

		}
	};

};

template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2]; // 기존의 C에서는 malloc으로 동적할당을 했다면 C++에서는 new 라는 키워드로 동적할당을 한다.
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData; // 기존의 C에서는 free라는 함수를 사용했다면 C++에서는 delete라를 사용한다. int[2] 배열의 동적할당은 delete[] 로 작성한다.
}

template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	// 힙 영역에 할당한 공간이 다 참
	if (m_iMaxCount <= m_iCount)
	{
		// 재할당
		resize(m_iMaxCount * 2);
	}

	// 데이터 추가
	m_pData[m_iCount++] = _Data;
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// 현재	최대 수용량 보다 더 적은 수치로 확장하려는 경우
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. 리사이즈 시킬 
	T* pNew = new T[_iResizeCount];

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. 기존 공간은 메모리 해제
	delete[] m_pData;

	// 4. 배열이 새로 할당된 공간을 가르키게 한다.
	m_pData = pNew;

	// 5. MaxCount 변경점 적용
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	// 시작을 가리키는 iterator 를 만들어서 반환해줌
	if (0 == m_iCount)
	{
		return iterator(this, m_pData, -1); // 데이터가 없는 경우, begin() == end()
	}
	else
	{
		return iterator(this, m_pData, 0); // 임시 객체로 만들어지는 순간 반환
	}
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	// 끝의 다음을 가리키는 iterator 를 만들어서 반환해줌
	return iterator(this, m_pData, -1);
}