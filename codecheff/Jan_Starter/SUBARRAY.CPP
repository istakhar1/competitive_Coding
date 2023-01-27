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

string s,t;
int n1,n2;
int DPsubsequenceCount(){
    vector<vector<int>> dp(n2+1,vector<int> (n1+1,0));
    if(n2>n1)return 0;
    // int dp[n1+1][n2+1];
    int m=1000000007;
    for(int i=0;i<n2;i++){
       dp[i][0]=0;
    }
    for(int i=0;i<n1;i++){
     dp[0][i]=1;
    }
  
    
  
    for(int i=1;i<=n2;i++){
        for(int j=1;j<=n1;j++){
            if(t[i-1]!=s[j-1]){
                dp[i][j]=dp[i][j-1]%m;
            }
            else{
                dp[i][j]= (dp[i][j-1]%m +dp[i-1][j-1]%m)%m;
            }
        }
    }

  
    //   for(auto x: dp){
    //     for(auto y:x){
    //         cout<<y<<" ";
    //     }
    //     cout<<"\n";
    // }

    return dp[n2][n1]%m;

}

int subsequenceCount(int index1,int index2, string temp){
    if(index2==n2 || index1==n1){
        return temp==t ?1:0;
    }
   
    
    int ans = subsequenceCount(index1+1,index2,temp);
    if(s[index1]==t[index2]){
        ans += subsequenceCount(index1+1,index2+1,temp+s[index1]);
    }
    return ans;

}

#define mod 1000000007
int mul(int a,int b){
    return ((a%mod)*(b%mod))%mod;
}

int binpow(int a,int b){
    if(b==0)
        return 1;
    int t = binpow(a,b/2);
    t= mul(t,t);
    if(b%2)
        return mul(t,a);
    return t;

}

int modInv(int a){
    int m=mod;
    return  binpow(a,m-2);
}
const int cz = 2e5 +1;
int fact[cz] , inFact[cz];

 void precomp(){
    fact[0]= inFact[0]=1;
    for(int i=1;i<cz;i++){
        fact[i]= mul(fact[i-1],i);
        inFact[i]= mul(inFact[i-1], i);
    }
 }


void c_p_c()
{   
    
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[i])
        cnt++;
    }
    if((n-cnt)%2){
       
        cout<<0<<"\n";
        
    }
    else{
    n-=cnt;
    
    int ans = mul(2,cnt);

    ans = mul(ans, mul(fact[n], mul(inFact[n/2], inFact[n/2])));
    cout<<ans<<"\n";
    }
   }
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    precomp();
    c_p_c();
    
    return 0;
}