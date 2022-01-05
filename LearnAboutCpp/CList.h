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
	int size() { return m_iCount; }

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(const iterator& _iter, const T& _data);

public:
	CList();
	~CList();

	class iterator
	{
	private:
		CList* m_pList;
		tListNode<T>* m_pNode; // null 인 경우, end iterator 로 간주
		bool m_bValid;

	public:
		T& operator* ()
		{
			return m_pNode->data;
		}

		bool operator ==(const iterator& _otheriter)
		{
			if (m_pList == _otheriter.m_pList && m_pNode == _otheriter.m_pNode)
			{
				return true;
			}
			return false;
		}

		bool operator !=(const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

		iterator& operator ++()
		{
			// end 에서 ++ 한 경우
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pNext;

			return *this;
		}

		iterator& operator ++(int)
		{
			iterator copyiter(*this);

			++(*this);

			return copyiter;
		}

		iterator& operator --()
		{
			// end 에서 ++ 한 경우
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pPrev;
			
			return *this;
		}

		iterator& operator --(int)
		{
			iterator copyiter(*this);

			--(*this);

			return copyiter;
		}

	public:
		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_bValid(false)
		{}

		iterator(CList<T>* _pList, tListNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bValid = true;
			}
		}

		~iterator()
		{

		}

		friend class CList;
	};
};

template<typename T>
inline void CList<T>::push_back(const T& _data)
{
	// 입력된 데이터를 저장할 노드를 동적할당 함
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	// 처음 입려된 데이터라면
	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		// 데이터가 1개 이상에서 입력된 경우
		// 현재 가장 마지막 데이터(tail)를 저장하고 있는 노드가
		// 새로 생성된 노드가 서로 가리키게 한다.
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;

		// List 가 마지막 노드의 주소값을 새로 입력된 노드로 갱신한다.
		m_pTail = pNewNode;
	}

	// 데이터 개수 증가
	++m_iCount;
}

template<typename T>
inline void CList<T>::push_front(const T& _data)
{
	// 새로 생생된 노드의 다음을 현재 헤드노드의 주소값으로 채움
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);
	
	// 현재헤드노드의 이전노드 주소값을 새로 생성된 노드의 주소로 채움
	m_pHead->pPrev = pNewNode;

	// 리스트가 새로 생성된 노드의 주소를 새로운 헤드주소로 갱신한다.
	m_pHead = pNewNode;

	// 데이터 개수 증가
	++m_iCount;
}

template<typename T>
typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this, m_pHead);
}

template<typename T>
typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);
}

template<typename T>
typename CList<T>::iterator CList<T>::erase(iterator& _iter)
{
	// iterator가 다른 List 쪽 요소를 가리키는 경우
	// iterator가 end iterator 인 경우
	if (this != _iter.m_pList || end() == _iter)
	{
		assert(nullptr);
	}

	// 헤더노드 일경우 -> _iter.m_pNode->pPrev 가 nullptr일 경우 헤더라고 할 수 있다.
	if (nullptr == _iter.m_pNode->pPrev)
	{
		m_pHead = _iter.m_pNode->pNext;
		_iter.m_pNode->pPrev = nullptr;
		free(_iter.m_pNode);
	}
	else if(nullptr == _iter.m_pNode->pNext)
	{
		// _iter 가 마지막 노드일 경우 m_pTail 수정해야됨!
		m_pTail = _iter.m_pNode->pPrev;

		// 데이터 노드 옮겨주기
		_iter.m_pNode->pPrev->pNext = nullptr;
	}
	else
	{
		// 데이터 노드 옮겨주기
		_iter.m_pNode->pNext->pPrev = _iter.m_pNode->pPrev;
		_iter.m_pNode->pPrev->pNext = _iter.m_pNode->pNext;

		// 데이터 실제로 지우기
		tListNode<T>* templist = _iter.m_pNode;
		free(_iter.m_pNode);

		// 뒤에 있는 데이터를 받기
		_iter.m_pNode = templist->pNext;
	}

	// 카운터 감소
	--m_iCount;

	// 리턴 받지 않으면 사용 못하게
	_iter.m_bValid = false;

	return iterator(this, _iter.m_pNode);
}

template<typename T>
typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
{
	if (end() == _iter)
	{
		assert(nullptr);
	}

	// 리스트에 추가되는 데이터를 저장 할 Node 생성
	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);

	// iterator 가 가르키는 노드가 헤드노드인 경우
	if (_iter.m_pNode == m_pHead)
	{
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;

		m_pHead = pNode;
	}
	else
	{
		// iterator 가 가르키고있는 노드의 이전으로 가서
		// 다음 노드 주소 파트를 새로 생성한 노드로 지정
		_iter.m_pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.m_pNode->pPrev;

		// iterator 가 가리키고있는 노드의 이전을 새로운 노드로 지정
		// 새로운 노드의 pNext 를 iterator 가 가리키고있는 노드로 지정
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;
	}

	++m_iCount;

	return iterator(this, pNode);
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
