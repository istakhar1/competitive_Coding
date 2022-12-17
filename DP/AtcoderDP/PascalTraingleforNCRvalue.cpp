#include<bits/stdc++.h>
#define ll long long int
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
ll NCR[1000][10]; 

void createNCRvalue(){
    int n=1000,m=10;
    for(int i=0;i<n;i++){
        NCR[i][0]=1;
    }
    for(int i=1;i<m;i++){
        for(int j=i;j<n;j++){
            if(i==j){
                NCR[j][i]=1;
            }
            else{
                NCR[j][i]= NCR[j-1][i] + NCR[j-1][i-1];
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<NCR[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
}
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

ll getSolution(int n){
    // cout<<NCR[n][5]<<" "<< NCR[n][6]<<" "<<NCR[n][7]<<"\n";
    return  NCR[n][5] + NCR[n][6]+ NCR[n][7];
}
 
void c_p_c()
{  
    createNCRvalue();
    int n;
    cin>>n;
    cout<<getSolution(n)<<"\n"; 

 
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