#include<bits/stdc++.h>
#define ll long long int
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ld long double

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

void c_p_c()
{  
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int dp[k+1];
    dp[0]=0;// my loss position;
    for(int i=1;i<=k;i++){
        dp[i]=0;
        for(int j=0;j<n;j++){
    //agar ham kisi k ko 0 bana sakte h to wo hamare liye winning position h
            if((i-a[j]>=0)&& dp[i-a[j]]==0){
                dp[i]=1;
                break;
            }
        }
    }
    cout<<(dp[k]?"First":"Second")<<"\n";
    
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