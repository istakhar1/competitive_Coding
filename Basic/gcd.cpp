#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
}
 
 int fact(int n);
 
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
// Returns factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
 
int32_t main()
{
    c_p_c();
    
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    //for(int i=0;i<n;i++) cout<<a[i];
    map<int,int>mp;
for(int i=0;i<n;i++){
	mp[a[i]]++;
}

int x=0;
while(x<n){
	int sum=0;
	int v=a[x];
	mp[v]--;
	for(auto x:mp){
		if(x.second>=2){
			sum+=nCr(x.second,2);
		}
	}
	mp[v]++;
	cout<<sum<<" ";
	x++;
}
    
    return 0;
}