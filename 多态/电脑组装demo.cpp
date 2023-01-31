#include<iostream>
using namespace std;
//抽象类
class CPU
{
public:
	virtual void calculator() = 0;
};
class VideoCard
{
public:
	virtual void display() = 0;
};
class Memory
{
public:
	virtual void storage() = 0;
};
//具体厂商
class IntelCPU :public CPU
{
public:
	virtual void calculator()
	{
		cout << "intel's CPU start working..." << endl;
	}
};
class IntelVC :public VideoCard
{
public:
	virtual void display()
	{
		cout << "intel's VideoCard start working..." << endl;
	}
};
class IntelMEM :public Memory
{
public:
	virtual void storage()
	{
		cout << "intel's Memory start working..." << endl;
	}
};

class LenovoCPU :public CPU
{
public:
	virtual void calculator()
	{
		cout << "Lenovo's CPU start working..." << endl;
	}
};
class LenovoVC :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo's VideoCard start working..." << endl;
	}
};
class LenovoMEM :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo's Memory start working..." << endl;
	}
};

//电脑类
class Computer
{
public:
	Computer(CPU *cpu, VideoCard *vc, Memory *mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
	void work()
	{
		m_cpu->calculator();
		m_vc->display();
		m_mem->storage();
	}
private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;

};

void test()
{
	CPU* cpu = new IntelCPU;//父类指针指向子类对象
	VideoCard* vc = new IntelVC;
	Memory* mem = new LenovoMEM;
	//第一台电脑
	Computer* computer1 = new Computer(cpu,vc,mem);
	computer1->work();
	delete computer1;
	//第二台
	cout << "第二台电脑开始..." << endl;
	Computer* computer2 = new Computer(new IntelCPU, new LenovoVC, new LenovoMEM);
	computer2->work();
	delete computer2;
}
int main()
{
	test();

	system("pause");
	return 0;
}

