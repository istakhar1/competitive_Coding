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
void solve(int n, string s){
    int i=0,j=n-1;
    int cnt=0;
    while(cnt<n){
        if(s[i]==s[j]){
            break;
        }
        if(s[i]!=s[j]){
            cnt+=2;
            i++;
            j--;
        }
    }
    cout<<n-cnt<<"\n";

}

void c_p_c()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        solve(n,s);
        // write code here
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