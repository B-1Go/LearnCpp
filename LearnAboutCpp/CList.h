#pragma once


template<typename T>
struct tListNode
{
	T data;
	tListNode<T>* pPrev;
	tListNode<T>* pNext;

	tListNode()
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{
	}

	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{

	}
};

template<typename T>
class CList
{
private:
	tListNode<T>* m_pHead;
	tListNode<T>* m_pTail;
	int m_iCount;

public:
	void push_back(const T& _data);
	void push_front(const T& _data);

public:
	CList();
	~CList();
};

template<typename T>
inline void CList<T>::push_back(const T& _data)
{
	// �Էµ� �����͸� ������ ��带 �����Ҵ� ��
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	// ó�� �Է��� �����Ͷ��
	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		// �����Ͱ� 1�� �̻󿡼� �Էµ� ���
		// ���� ���� ������ ������(tail)�� �����ϰ� �ִ� ��尡
		// ���� ������ ��尡 ���� ����Ű�� �Ѵ�.
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;

		// List �� ������ ����� �ּҰ��� ���� �Էµ� ���� �����Ѵ�.
		m_pTail = pNewNode;
	}

	// ������ ���� ����
	++m_iCount;
}

template<typename T>
inline void CList<T>::push_front(const T& _data)
{
	// ���� ������ ����� ������ ���� ������� �ּҰ����� ä��
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);
	
	// ����������� ������� �ּҰ��� ���� ������ ����� �ּҷ� ä��
	m_pHead->pPrev = pNewNode;

	// ����Ʈ�� ���� ������ ����� �ּҸ� ���ο� ����ּҷ� �����Ѵ�.
	m_pHead = pNewNode;

	// ������ ���� ����
	++m_iCount;
}

template<typename T>
CList<T>::CList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount(0)
{

}

template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeleteNode = m_pHead;

	while (pDeleteNode)
	{
		tListNode<T>* pNext = pDeleteNode->pNext;
		delete(pDeleteNode);
		pDeleteNode = pNext;
	}
}