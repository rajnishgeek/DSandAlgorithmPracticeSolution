#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

/*//*****working******
class fun {
public:
	void operator()()
	{
		cout << "inside fun object call";
	}
}
int main()
{
	fun f;
	f();//if is looking like function but it is an object
	return 0;
}
*/

/*
//*****working***
class fun {
public:
	void operator()(string s)
	{
		cout << "inside fun object call with " << s;
	}
}
int main()
{
	fun f;
	f("C++");//if is looking like function but it is an object
	return 0;
}
*/

class Person {
public:
	string name;
	int age;

	Person()//null constructor
	{}

	Person(string n, int a)
	{
		name = n;
		age = a;
	}
}

class PersonCompare {
public:
	bool operator()(Person A, Person B)
	{
		return A.age < B.age;
	}
}
int main()
{
	int n;
	cin >>;

	priority_queue<Person, vector<Person>, PersonCompare> pq;

	for (int i = 0; i < n; i++)
	{
		string name;
		int age;
		cin >> name >> age;
		Person p(name, age);
		priority_queue.push(p);
	}
	return 0;
}