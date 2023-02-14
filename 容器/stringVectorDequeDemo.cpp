/*
* 评委打分案例：5位选手，ABCDE，10名评委对每一名选手打分，去除最低分和最高分，取平均分
* 步骤：
* 1.vector包含5名选手
* 2.遍历vector，取出每一个选手，执行for循环，把10个评分放入deque容器
* 3.sort对deque容器排序，去除最高分和最低分
* 4.deque容器遍历求总分
* 5.求平均分
*/

#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;
//选手类
class Person 
{
public:
	Person(string name, int score)
	{
		m_Name = name;
		m_Score = score;
	}
	string m_Name;
	int m_Score;
};

void printPerson(vector<Person> v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).m_Name << "的分数为：" << (*it).m_Score << endl;
	}
}
void createPerson(vector<Person> &v) 
{
	string name = "选手";
	string nameSeed = "ABCDE";
	int score = 0;
	
	for (int i = 0; i < 5; i++)
	{
		name = "选手";
		name += nameSeed[i];
		v.push_back(Person(name, score));
	}
}
void setScore(vector<Person>& v)
{
	deque<int> d;
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//评委打分，60-100随机数,放入deque容器
		for (int i = 0; i < 10; i++)
		{
			d.push_back(rand()%40+61);
		}
		//排序
		sort(d.begin(),d.end());
		//去掉最低分和最高分
		d.pop_back();
		d.pop_front();
		//求平均数
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();

		it->m_Score = avg;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	vector<Person> v;
	createPerson(v);
	//printPerson(v);
	setScore(v);
	printPerson(v);
	system("pause");
	return 0;
}

