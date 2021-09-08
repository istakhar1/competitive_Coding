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

double calculate(double mid,int n){
	double val=1.0;
	for(int i=0;i<n;i++)
		val*=mid;
	return val;
}
double nth_root_of_m(int n,int m){
 	double low=0.0;
 	double high=(double)m;
 	double eps=1e-6;
 	while((high-low)>eps){
 		double mid=(low +high)/2.0;
 		if(calculate(mid,n)<m){
 			low=mid;
 		}
 		else{
 			high=mid;
 		}


 	}
 	return low;
 }

int32_t main()
{
    c_p_c();
    int n,m;
    cin>>n>>m;
    cout<<nth_root_of_m(n,m);
    return 0;
}