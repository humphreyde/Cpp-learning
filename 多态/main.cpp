#include<iostream>
using namespace std;

//利用多态实现饮品制作
//抽象类，基类
class AbstractDrinking
{
public:
	//纯虚函数
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
//制作咖啡类 子类必须重写纯虚函数，否则无法实例化对象
class MakeCoffee :public AbstractDrinking
{
public:
	virtual void Boil() 
	{
		cout << "热水" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	virtual void PutSomething()
	{
		cout << "加入糖和牛奶" << endl;
	}
};
//制作茶类
class MakeTea :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "热水" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	virtual void PutSomething()
	{
		cout << "加入柠檬" << endl;
	}
};

//多态使用
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

