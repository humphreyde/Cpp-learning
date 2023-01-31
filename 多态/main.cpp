#include<iostream>
using namespace std;

//���ö�̬ʵ����Ʒ����
//�����࣬����
class AbstractDrinking
{
public:
	//���麯��
	virtual void Boil() = 0;
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void PutSomething() = 0;
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};
//���������� ���������д���麯���������޷�ʵ��������
class MakeCoffee :public AbstractDrinking
{
public:
	virtual void Boil() 
	{
		cout << "��ˮ" << endl;
	}
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;
	}
	virtual void PutSomething()
	{
		cout << "�����Ǻ�ţ��" << endl;
	}
};
//��������
class MakeTea :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	}
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;
	}
	virtual void PutSomething()
	{
		cout << "��������" << endl;
	}
};

//��̬ʹ��
void makeDrink(AbstractDrinking* abc)
{
	abc->makeDrink();
	delete abc;
}
int main()
{
	makeDrink(new MakeTea);
	makeDrink(new MakeCoffee);
	system("pause");
	return 0;
}

