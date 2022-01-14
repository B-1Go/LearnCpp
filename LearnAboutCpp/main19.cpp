
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

	virtual void output()
	{
		cout << "Parent" << endl;
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
	{
		cout << "CParent �Ҹ��� �Դϴ�." << endl;
	}
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

	// ��ӹ��� �θ�Ŭ������ �Լ��� ������(�������̵�) ��
	void output()
	{
		cout << "Child" << endl;
	}

	void NewFunc()
	{
		cout << "�ڽĸ� ���� �Լ��Դϴ�" << endl;
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
	{
		cout << "CChild �Ҹ��� �Դϴ�." << endl;
		// ���� ������ ������ �����Ϸ��� ~CParent() ȣ���ϴ� �ڵ带 ����� ������ ȣ���� �ȴ�!
	}
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
	//FuncA();

	cout << "Function A" << endl;
		
	FuncA();
}

int main()
{
	// FuncB();

	// ��ü���� ��� Ư¡
	// 1. ĸ��ȭ (���м�)
	// 2. ���
	// 3. ������
	// 4. �߻�ȭ

	CParent parent;
	//parent.output();

	CChild child;
	//child.output();
	//child.CParent::output(); // �̷��� �θ��� �Լ��� ȣ�� �� �� ������, �̷��� �ϸ� �������̵��� �ǹ̰� ����ȴ�.
	// parent.SetInt(10);
	//child.SetInt(10);

	// ���
	// �ڽ� or �θ� Ŭ������ ��Ӱ��迡�� �ٸ� Ŭ���� ����� �ʱ�ȭ �� �� ����.
	// ������ ȣ�� ���� �ڽ� -> �θ�
	// ������ ���� ����, �ʱ�ȭ ���� �θ� -> �ڽ�
	
	// �Ҹ��� ���� �� ȣ�� ����, �ڽ� -> �θ�
	
	// ���! ��ӹ��� child ��ü�� �����ϸ�
	// ������, �Ҹ��� �Ѵ� child ���� ȣ���� �ȴ�. ������!
	// �ڽ� �����ڴ� ȣ�⸸ ���� �� �� ������ �θ� �����ں��� ������ �Ϸ�ǰ� ����Ǹ� ���������� ����ǰ� ����ȴ�.
	// �ڽ� �Ҹ��ڴ� ȣ�⵵ ���� �ǰ� ���൵ ���� �Ѵ��� �θ� �Ҹ��ڸ� ȣ���ϰ� �����Ѵ��� ���������� ���ᰡ �ȴ�.

	// ���� ���̵�(���� �ε��̶� �򰥸� ����!) -> ���� ���̵��� ��Ӱ��� �Ͼ�� ���̴�.
	// �������̵��̶�? �θ� Ŭ������ ����Լ��� �ڽ��ʿ��� ������ �����ν�, �ڽ� Ŭ������ ������ ����� ȣ��ǵ��� �Ѵ�.

	
	
	// ���⼺�� �����ϱ� ���ؼ� ��� And �����͸� �����ϰ� �־�ߵȴ�.
	// 

	CParent* pParent = &parent;
	CChild* pChild = &child;

	// CParent�� ��ӹ��� CChild�� ��ü�� ����� �޸� ������ CParent������ �Ҵ�ǰ� �ڿ� CChild ������ �پ �Ҵ�ȴ�.
	// ����Ʈ �������� ������ �ϸ� CParent* �� CPchild�� ���� �� �ִ�.
	// ������ ���������� ���� �� ��ü�� CParent���� CChild�� ���� �� �� �� ����.
	// �׷��� �׳� CParent�� ��޵Ǵϱ� ���⼺�� �ƴ϶� �׳� ���ϼ��ƴѰ�? ���� C++������ virtual�� �����ϹǷ�
	// CParent* pParent = &child;
	// CChild* pChild = &parent;
	

	parent.output();
	pParent = &parent;
	pParent->output();

	child.output();
	pParent = &child;
	pParent->output();

	// virtual �����Լ� -> ����: �� ��ü�� ���������� ��� �� �մܿ� ��ġ���Ͽ� ��� CParent�� ������ �ص� child()ȣ��� ���¸� �����ؼ� CChild output()�� �θ��� �ִ�.

	((CChild*)pParent)->NewFunc();

	CChild* pChildt = dynamic_cast<CChild*>(pParent); // ĳ���� ���н� nullptr�� ��ȯ��
	if (nullptr != pChildt)
	{
		pChildt->NewFunc();
	}
	
	// ���⼺, �����Լ�(virtual)
	// �θ� ������ Ÿ������, �θ� Ŭ�����κ��� �Ļ��Ǵ� �ڽ�Ŭ���� ��ü���� �ּҸ� ����ų �� �ִ�.
	// ��� ��ü�� �θ� Ŭ���� Ÿ������ �ν��ϰ� �Ǳ� ������, ���� ��ü�� �������� �� �� ����.
	// virtual Ű���带 ���ؼ�, �� Ŭ������ �ڽŸ��� ������ �����Լ� ���̺��� ������ �ȴ�.
	// �� Ŭ������ ��ü���� �����Լ� ���̺� �����Ϳ��� �ش� Ŭ������ �´� ���̺��� ����Ű�� �ȴ�.
	// �� ���̺��� �ش� Ŭ������ �����Լ����� ���

	// �ٿ� ĳ����
	// �θ� Ŭ�������� ������ ����, ���� �ڽ��ʿ����� �߰��� �Լ��� ȣ�� �ϰ� ���� ��
	// �ڽ� ������Ÿ������ �Ͻ������� ĳ���� �ؼ� ȣ���Ѵ�.
	// ������ �߻� �� �� �ֱ� ������ dynamic_cast �� �����ϰ� Ȯ���� �� �� �ִ�.
	// RTTI(Run Time Type Identification or Information)

	// �߻�ȭ
	// ���� ��ü�� ������ ������ Ŭ������ �ƴ�, ����� ���ؼ� �����ؾ��� ������ �����ϴ� ��� �������� ������� Ŭ����
	// virtual , = 0 (1 �� �̻��� ���������Լ��� �����ϸ� �߻�Ŭ������ �ȴ�)

	return 0;
}