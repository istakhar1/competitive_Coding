#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
// #define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vvi             vector<vector<int>>
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
#define ld              long double
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


// here w= 10^9 so we cant take w in array but v= 10^3 so we can take it if we take it then we shoud store w;;
//  if dp[index][value]= weight if this is <= w then value shoud be answer 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

char flip(char ch) { return (ch == '0') ? '1' : '0'; }

int getSolution(string str, char expected)
{
    int flipCount = 0;
    for (int i = 0; i < str.length(); i++) {
        // if current character is not expected, increase
        // flip count
        if (str[i] != expected){
            flipCount++;
            str[i+1]=str[i];
            str[i]='1';
            // s[i+1]=s[i];
            // s[i]='1';
        }
        
 
        
        // expected = flip(expected);
    }
    return flipCount;
}



 
void c_p_c()
{   
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int ans=INT_MAX;
        for(int i=0;i<n-k;i++){
            string req = s.substr(i,k);
            ans=min(ans,getSolution(req,'1'));
        }
        if(ans==INT_MAX){
            ans=1;
        }
        cout<<ans<<"\n";
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