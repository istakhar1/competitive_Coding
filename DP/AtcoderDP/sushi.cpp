#include<bits/stdc++.h>
#define ll long long int
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ld long double
int n;
const int N=301;

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
ld memo[N][N][N];

ld dp(int zero,int one, int two,int three){
    // cout<<zero<<" "<<one<<" "<<two<<" "<<three<<"\n";
    if(one+two+three==0) return 0;
    ld &ans= memo[one][two][three];
    if(ans!=-1.00) return ans;
    ans = (ld)n;
    if(one) ans+= one*dp(zero+1,one-1,two,three);
    if(two) ans+= two*dp(zero,one+1,two-1,three);
    if(three) ans+= three*dp(zero,one,two+1,three-1);

    ans/=(ld)(n-zero);
    return ans;

}

 
void c_p_c()
{  
    cin>>n;
    int c[4]={0,0,0,0};
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        c[a]+=1;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                memo[i][j][k]=-1.00;
            }
        }
    }
    cout<<setprecision(10)<<fixed;
    cout<<dp(c[0],c[1],c[2],c[3]);
    
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