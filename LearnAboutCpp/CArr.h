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
	void push_back(const T& _Data); // Push_back �Լ��� ������ ���簡 ��ȿ�����̿��� ���� �ϴ� ������� �ٲ�
	void resize(int _iResizeCount);
	T* data() { return m_pData; }
	int size() { return m_iCount; }
	int capacity() { return m_iMaxCount; }
	T& operator[] (int idx); //���۷���

	class iterator; // ���� ����
	iterator begin();
	iterator end();

public:
	// ������
	CArr();
	// �Ҹ���
	~CArr();

	// inner Ŭ������ �����ϰ��ִ� Ŭ������ private ����� ���� ����
	class iterator
	{
	private:
		CArr* m_pArr; // iterator�� ����ų �����͸� �����ϴ� �����迭 �ּ�
		T* m_pData; // �����͵��� ���� �ּ�
		int m_iIdx; // ����Ű�� �������� �ε���

	public:
		T& operator* ()
		{
			// iterator�� �˰��ִ� �ּҿ�, �����迭�� �˰� �ִ� �ּҰ� �޶��� ���(���� Ȯ������ �ּҰ� �޶��� ���)
			// iterator�� end iterator �� ���
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
			{
				assert(nullptr);
			}

			return m_pData[m_iIdx];
		}

		// ����
		iterator& operator ++()
		{
			// 2. end iterator �� ���
			// 3. iterator�� �˰��ִ� �ּҿ�, �����迭�� �˰� �ִ� �ּҰ� �޶��� ���(���� Ȯ������ �ּҰ� �޶��� ���)
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
			{
				assert(nullptr);
			}

			// 1. iterator�� ������ �����͸� ����Ű�� �ִ� ���
			// --> end iterator�� �ȴ�.
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

		// ++ ���� -> �����δ� ����ó�� ������ ���� ���������� ȣ�������, �������� ����Ǵ� �� ó�� �����ϴ� ���̴�.
		iterator operator ++(int) // ���纻�ϰ�, �ƹ�������� int�� �־��ָ� �����Ϸ��� ���������ڷ� �Ǵ��Ѵ�.
		{
			iterator copy_iter = *this; // ��������ڷ� �˾Ƽ� �����Ϸ��� ���ؼ� ó����

			+= (*this);

			return copy_iter;
		}

		// -- ����, ���� ���� �����غ���
		iterator& operator --()
		{

			return *this;
		}
		
		// �񱳿����� ==, !=
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
	m_pData = new T[2]; // ������ C������ malloc���� �����Ҵ��� �ߴٸ� C++������ new ��� Ű����� �����Ҵ��� �Ѵ�.
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData; // ������ C������ free��� �Լ��� ����ߴٸ� C++������ delete�� ����Ѵ�. int[2] �迭�� �����Ҵ��� delete[] �� �ۼ��Ѵ�.
}

template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	// �� ������ �Ҵ��� ������ �� ��
	if (m_iMaxCount <= m_iCount)
	{
		// ���Ҵ�
		resize(m_iMaxCount * 2);
	}

	// ������ �߰�
	m_pData[m_iCount++] = _Data;
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// ����	�ִ� ���뷮 ���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. �������� ��ų 
	T* pNew = new T[_iResizeCount];

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� �����Ų��.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. ���� ������ �޸� ����
	delete[] m_pData;

	// 4. �迭�� ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	m_pData = pNew;

	// 5. MaxCount ������ ����
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
	// ������ ����Ű�� iterator �� ���� ��ȯ����
	if (0 == m_iCount)
	{
		return iterator(this, m_pData, -1); // �����Ͱ� ���� ���, begin() == end()
	}
	else
	{
		return iterator(this, m_pData, 0); // �ӽ� ��ü�� ��������� ���� ��ȯ
	}
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	// ���� ������ ����Ű�� iterator �� ���� ��ȯ����
	return iterator(this, m_pData, -1);
}