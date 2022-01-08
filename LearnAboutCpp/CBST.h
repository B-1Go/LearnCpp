#pragma once



template <typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};


template <typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2> pair;

	tBSTNode* pParent;
	tBSTNode* pLeftChild;
	tBSTNode* pRightChild;
};


template <typename T1, typename T2>
class CBST
{
private:
	tBSTNode<T1, T2>* m_pRoot; // 루트 노드 주소
	int m_iCount; // 데이터 개수

public:
	bool insert(const tPair<T1, T2>& _pair);

public:
	CBST()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{}
};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>();
	pNewNode->pair = _pair;
	pNewNode->pParent = nullptr;
	pNewNode->pLeftChild = nullptr;
	pNewNode->pRightChild = nullptr;


	// 첫번째 데이터 라면
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot;

		while (true)
		{
			if (pNode->pair.first < pNewNode->pair.first)
			{
				if (nullptr == pNode->pRightChild)
				{
					pNode->pRightChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
				{
					pNode = pNode->pRightChild;
				}
			}
			else if (pNode->pair.first > pNewNode->pair.first)
			{
				if (nullptr == pNode->pLeftChild)
				{
					pNode->pLeftChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
				{
					pNode = pNode->pLeftChild;
				}
			}
			else
			{
				return false;
			}
		}
	}

	// 데이터 개수 증가
	++m_iCount;

	return true;
}
