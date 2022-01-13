
#include <map>
#include <set>

#include <string>
#include <iostream>

using::std::cout;
using::std::endl;

class CParent
{
protected:
	int m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}

public:
	CParent()
		: m_i(0)
	{
		cout << "CParent ������ �Դϴ�." << endl;
	}
	CParent(int _a)
		: m_i(_a)
	{}
	~CParent()
	{}
};

class CChild : public CParent
{
private:
	float m_f;

public:
	void SetFloat(float _f)
	{
		m_f = _f;
		m_i = 100;
	}

public:
	CChild()
		: CParent(1000) // ��, �ʱ�ȭ �ϱ� ���� CParent() �����ڰ� ���� �Ǿ� �ִٰ� ���� �ȴ�. -> �����Ϸ��� ������ ������ ���س���. �����ε� �Լ��� �̿��ϰ� ������ ���ڸ� �־ �������� �ȴ�.
		, m_f(0.f) // �� �κ��� �ʱ�ȭ�� �� class�� �����ڰ� ó���Ѵ�. -> ������ ��� �ɱ�??
		// ��ü�� �Ǵ� �κ� ���� ȣ���� �Ѵ�. �׷��� ��ӹ��� �����ڸ� ���� �����ϱ� ������ CParent�� ���� ȣ�� �Ȱ� ó�� ���δ�.
	{
		m_i = 0;
		cout << "CChild ������ �Դϴ�." << endl;
	}
	~CChild()
	{}
};

class CChildChild : public CChild
{
private:
	long long m_ll;
	// �޸𸮰� ��ӹ��� ������� �پ ���������. CParent+CChild+CChildChild -> �̰� ���������� ������ �߿��� ������.
};

void FuncA()
{
	cout << "Function A" << endl;
}

void FuncB()
{
	FuncA();

	cout << "Function A" << endl;
}

int main()
{
	FuncB();

	// ��ü���� ��� Ư¡
	// 1. ĸ��ȭ (���м�)
	// 2. ���
	// 3. ������
	// 4. �߻�ȭ

	// CParent parent;
	CChild child;

	// parent.SetInt(10);
	child.SetInt(10);

	// ���
	// �ڽ� or �θ� Ŭ������ ��Ӱ��迡�� �ٸ� Ŭ���� ����� �ʱ�ȭ �� �� ����.
	// ������ ȣ�� ���� �ڽ� -> �θ�
	// ������ ���� ����, �ʱ�ȭ ���� �θ� -> �ڽ�

	return 0;
}