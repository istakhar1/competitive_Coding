#include<bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;


// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

void c_p_c()
{  
 int t;
 cin>>t;
//  cout<<t;
 while(t--){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int index=1;
    int val=1;
    int ans[n+1];
    bool notpossible = true;
    for(int i=1;i<=n;i++){
        // cout<<index<<" ";
        // cout<<a[i]<<" ";
        if(a[i]==-1){
            // cout<<a[i]<<" ";
            continue;
        } 
        int countOfcurrvalue = a[i];
         if(index+countOfcurrvalue>n+1){
            notpossible=false;
            cout<<"-1"<<"\n";
            break;
        }

        int ocr=countOfcurrvalue;
        for(int j=i;j<=n;j++){
            if(countOfcurrvalue==0){
                break;
            }
            
            if(a[j]==ocr){
                ans[j]=val;
                a[j]=-1;
                countOfcurrvalue-=1;
                index+=1;
            }
                
        
        }
        val+=1;
    }
    if(notpossible){
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
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