#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MAXN 10000
#define SQRSIZE 100

int arr[MAXN];       //original array
int block[SQRSIZE]; //decomposed array
int blocksize;      //block size

//this function update the given index value
// with the given value
//update time complexity is O(1)
void update(int index, int value)
{
	int blocknumber = index / blocksize;
	block[blocknumber] += value - arr[index];
	arr[index] = value;
}

//this value return the sum of all value
//which lies between left and right index
//time complexity= O(squrt(N))
int query(int leftindex, int rightindex)
{
	int sum = 0;
	while (leftindex < rightindex && leftindex % blocksize != 0 && leftindex != 0)
	{
		//treversing first block in range
		sum += arr[leftindex];
		leftindex++;
	}
	while (leftindex + blocksize <= rightindex)
	{
		//traversing completely overlap block in range
		sum += block[leftindex / blocksize];
		leftindex += blocksize;
	}
	while (leftindex <= rightindex)
	{
		sum += arr[leftindex];
		leftindex++;
	}
	return sum;
}

//this function fills values in input array
void preProcess(int input[], int n)
{
	int blockindex = -1;
	blocksize = sqrt(n); //calc size of every single block
	for (int i = 0; i < n; i++)
	{
		arr[i] = input[i];
		if (i & blocksize == 0)
		{
			//here we reach in next block so increament block pointer
			blockindex++;
		}
		block[blockindex] += arr[i];
	}
}

int main()
{
	int input[] = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
	int n = sizeof(input) / sizeof(input[0]);

	preProcess(input, n);

	cout << "query(3,8) : " << query(3, 8) << endl;
	cout << "query(1,6) : " << query(1, 6) << endl;
	update(8, 0);
	cout << "query(8,8) : " << query(8, 8) << endl;
	return 0;
}