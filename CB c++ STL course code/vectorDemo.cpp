#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include "vector.h" //this is including user defined header file

int main()
{
	Vector<int > v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.pop_back();

	cout << "Capacity" << v.capacity() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
}