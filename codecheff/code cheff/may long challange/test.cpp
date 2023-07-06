#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#define ll long long int
int mod = 1e9+7;
using namespace std;
 

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int bitMaskDP(int p[],int n){
    reverse(p, p + n);
	    ll ans[n + 1], res = 0;
	    memset(ans, 0, sizeof(ans));
	    for(int i = 0; i < n; i++) {
	        int now = p[i];
	        ans[now] = 1;
	        int masks = (now - 1)&now;//removing smallest set bit
	       // cout<<"first MAsk"<<masks;
	        while(masks) {
	            ans[now] += ans[masks];//numbers are already there from 1->n
	            ans[now] %= mod;
	            masks -= 1;
	            masks &= now;//these 2 lines create a smaller maks which is a submask of our supermask
	        }
	        res += ans[now];
	        res %= mod;
	    }
	   return  res;
    
}




 
void c_p_c()
{   
    int mod= 1e9+7;
    int t;
    cin>>t;
    cout<<t;
    while(t--){
        int n;
        cin>>n;
        cout<<n<<"\n";
        int arr[n];
        for(int i=0;i<n;i++)cin>>arr[i];
        int ans=bitMaskDP(arr,n);
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