
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum of sum
// of lengths of rectangles and squares
// formed using given set of sticks
void findSumLength(vector<int> arr,int n)
{

	// Stores the count of frequencies
	// of all the array elements
	map<int,int> freq;
	for(int i:arr) freq[i] += 1;

	// Stores frequencies which are at least 2
	map<int,int> freq_2;

	for (auto i:freq)
	{
		if (freq[i.first] >= 2)
			freq_2[i.first] = freq[i.first];
	}

	// Convert all frequencies to nearest
	// smaller even values.
	vector<int> arr1;
	for (auto i:freq_2)
		arr1.push_back((i.first) * (freq_2[(i.first)]/2)*2);
	sort(arr1.begin(), arr1.end());

	// Sum of elements up to
	// index of multiples of 4
	int summ = 0;
	for (int i:arr1)
		summ += i;

	// Print the sum
	cout << summ;
}

// Driver Code
int main()
{
vector<int> arr = {5, 3, 2, 3, 6, 4, 4, 4, 5, 5, 5};
int n = arr.size();
findSumLength(arr, n);
return 0;
}

// This code is contributed by mohit kumar 29.
