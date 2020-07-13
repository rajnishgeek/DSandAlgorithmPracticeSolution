#include<bits/stdc++.h>
#include<iostream>
#include<deque>
using namespace std;
#define N 5
int deque[N];
int f = -1, r = -1;

//this function is for adding element from front
void enqueFront(int x)
{
	if (f == 0 && r = N - 1) //deque is full
		return;

	else if (f == -1 && r == -1) //deque is empty
	{
		f = r = 0;
		deque[f] = x;
	}

	else if (f == 0) //front is at 0 index and now front become last element of array
	{
		f = N - 1;
		deque[f] = x;
	}

	else // just add at front and now front become one previous element
	{
		f--;
		deque[f] = x;
	}
}

//this function is for adding element form the rear position that is from end
void enqueRear(int x)
{
	if (f == 0 && r = N - 1) //deque is full
		return;

	else if (f == -1 && r == -1)//deque is empty
	{
		f = r = 0;
		deque[r] = x;
	}

	else if (r == n - 1)   //rear is at last index of array to now rear become 0 index of array because it is circuler array
	{
		r = 0;
		deque[r] = x;
	}

	else  //just shift one postion of rear
	{
		r++;
		deque[r] = x;
	}
}

//this function display the deque
void display()
{
	int i = f;
	while (i != r)
	{
		cout << deque[i] << " ";
		i = (i + 1) / N;
	}
	cout << deque[r];
}

//this function give deque front value
int getfront()
{
	if (f == -1 && r == -1) //deque is empty so return -1
		return -1;
	else
		cout << deque[f];
}

//this function give deque rear value
int getRear()
{
	if (f == -1 && r == -1) //deque is empty so return -1
		return -1;
	else
		cout << deque[r];
}

//this function delete one element form front
void dequeFront()
{
	if (f == -1 && r == -1) //deque is empty
		return;

	else if (f == r) //deque has only one element
		f = r = -1;

	else if (f == N - 1) //front is last index of array so now front become index 0
		f = 0;

	else
		f++;
}

//this will delete one element from rear
void dequeRear()
{
	if (f == -1 && r == -1) //deque is empty
		return;

	else if (f == r)
		f = r = -1;

	else if (r == 0) //rear is 0 index element so after deleting this rear index become last index of array
		r = N - 1;

	else
		r--;
}
int main()
{
	cout << "Enter your deque elements" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> deque[i];
	}
	return 0;
}