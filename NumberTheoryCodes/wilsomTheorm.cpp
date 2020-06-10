#include <iostream>
using namespace std;
int factmod(int n, int p) {
    int res = 1;
    while (n > 1) {
        res = (res * ((n/p) % 2 ?  p-1 : 1)) % p;
        for (int i = 2; i <= n%p; ++i)
            res = (res * i) % p;
        n /= p;
    }
    return res % p;
}

int main() {

	// your code here
	int t;
	cin>>t;
	int a[t];
	for(int i=0;i<t;i++)
	{
		int n,p;
		cin>>n>>p;
		a[i]=factmod(n,p);
	}
	for(int i=0;i<t;i++)
	 cout<<a[i]<<endl;
    return 0;
}
