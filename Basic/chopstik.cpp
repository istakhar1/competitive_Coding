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
 
int32_t main()
{
    c_p_c();
    long long n,d;
    cin>>n>>d;
    vector<long long> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
   // sort(a.begin(),a.end());

	 map<long long,int>mp;
	for(int i=0;i<n;i++){
		mp[a[i]]++;
	}
// vector<bool>flag(n,true);

	int count=0;
	// for(int i=0;i<n;i++){
	// 	if(flag[i]==true){
	// 		flag[i]=false;
	// 		for(int j=i+1;j<n;j++){
	// 			if((a[j]-a[i])<=d && (a[j]-a[i])>=0){
	// 				count++;
	// 				flag[j]=false;
	// 				break;
	// 			}
	// 		}
	// 	}
		
	// } 
	for(auto x:mp){
		long long val=mp.lower_bound((x.first)+1)->first;
		if((val - x.first)>=0 && (val - x.first)<=d){			
			int pair=min(val,x.second);
			count+=pair;
			mp[x.first]-=pair;
			mp[val]-=pair;
		}
	}
	cout<<count;
    
    return 0;
}