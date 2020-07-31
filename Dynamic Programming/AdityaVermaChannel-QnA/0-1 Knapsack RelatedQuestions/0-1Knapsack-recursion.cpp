#include<bits/stdc++.h>
using namespace std;

int knapsackMaxProfit(int weight[], int value[], int n, int W)
{
	//base case
	//if our array is null so return 0
	//if our given weight of bag (i.e W ) is 0 so return 0
	if(n==0 || W==0)
		return 0;

	//checking here if the weight element is less than or equal to given bag Weight
	//then include the weight
	if(weight[n-1]<=W)
		return max(value[n-1]+knapsackMaxProfit(weight,value,n-1,W-weight[n-1]),knapsackMaxProfit(weight,value,n-1,W));

    //here checking if our weight element become grater than our Bag value
    //then we not include the current weight element in the bag
    if(weight[n-1]>W)
		return knapsackMaxProfit(weight,value,n-1,W);
}
int main()
{
    int weight[]={1,3,4,5},value[]={1,4,5,7};
    int n=sizeof(weight)/sizeof(weight[0]);
    int W=7;
    cout<<knapsackMaxProfit(weight,value,n,W)<<endl;
	return 0;
}
