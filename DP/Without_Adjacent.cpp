#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

long long  FindMaxSum(long long  arr[], int n)
    {
        long long  incl = arr[0];
        long long  excl = 0;
        long long  excl_new;
        int i;
 
        for (i = 1; i < n; i++)
        {
            /* current max excluding i */
            excl_new = (incl > excl) ? incl : excl;
 
            /* current max including i */
            incl = excl + arr[i];
            excl = excl_new;
        }
 
        /* return max of incl and excl */
        return ((incl > excl) ? incl : excl);
    }

int main() {

int t;cin>>t;
while(t--){
	int n;
	cin>>n;
	long long arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	cout<< FindMaxSum(arr,n)<<"\n";

	// Your code here

}
	return 0;
}