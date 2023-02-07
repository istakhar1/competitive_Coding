#include<bits/stdc++.h>
using namespace std;

void c_p_c()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
        }
        map<int,int> mp;

        bool flag= true;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])!=mp.end()){
                flag=false;
                cout<<"Yes";
                break;
            }
            else{
                mp[arr[i]]=i;
            }
        }
        if(flag){
            cout<<"no";
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