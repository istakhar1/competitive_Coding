#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
 

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

 
void c_p_c()
{   
 int t;
 cin>>t;
 while(t--){
 vector<int>x(3),y(3);
 cin>>x[0]>>y[0];
 cin>>x[1]>>y[1];
 cin>>x[2]>>y[2];
 sort(x.begin(),x.end());
 sort(y.begin(),y.end());
 if(x[0]==x[1]){
    if(y[0]==y[1] || y[1]==y[2]){
        cout<<"NO";
        continue;
    }else{
        cout<<"YES"<<"\n";
        continue;
    }
 }
 else if(x[1]==x[2]){
      if(y[0]==y[1] || y[1]==y[2]){
        cout<<"NO";
        continue;
    }else{
        cout<<"YES"<<"\n";
        continue;
    }
 }
 else{
    cout<<"YES"<<"\n";
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
    c_p_c();
    
    return 0;
}