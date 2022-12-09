#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
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
int getSolution(int arr[],int n,int K){
    int dp[n+1];
    dp[0]=0;
    dp[1]=abs(arr[0]-arr[1]);
    for(int i=2;i<=K && i<n;i++){
        dp[i]=INT_MAX;
        for(int j=0;j<=i;j++){
            dp[i] =  min(dp[i],dp[j] + abs(arr[i]-arr[j]));
        }
    }
    
    for(int i=K+1;i<n;i++){
        dp[i]=INT_MAX;
        for(int j=(i-K);j<=i && j<n;j++){
            dp[i] =  min(dp[i],dp[j] + abs(arr[i]-arr[j]));
        }
    }
    
    return dp[n-1];
} 
 
void c_p_c()
{
    int n,k;
    cin>>n;
    cin>>k;
    // cout<<n<<k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<getSolution(arr,n,k);
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    c_p_c();
    
    return 0;
}