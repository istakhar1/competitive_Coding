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

int moduloMultiplicativeInverse(int a,int b){
    if(a==0){
        return b==0;
    }
    int ans=1;
    while(b){
        if(b&1) ans = (ans*a)%mod;
        b>>=1LL;
        a=(a*a)%mod;
    }
    return ans;
}
// 1 + 1+ 1=3  if we do 3-1 =2 but sum is 2 -1 =1 this resoon here sum - = 2*a[0]

void solve(int n, vi a){
           int sum = 0;
        int negs = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] < 0) {
                ++negs;
                a[i] = -a[i];
            }
            sum += a[i];
        }
        sort(a.begin(), a.end());
        if(negs & 1) sum -=  2*a[0];
        cout << sum << "\n";
    return ;

}

void c_p_c()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // write code here
        vi a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        solve(n,a);
    }
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