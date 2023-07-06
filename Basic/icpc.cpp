#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    
    int n,x;
    cin>>n>>x;
    int count=0;
    if(n%2!=0 and x==0){
        cout<<-1<<"\n";
        continue;
    }
    if(n==x){
        cout<<1<<"\n";
        continue;
    }
    while(n>1 and n>x){
        int p=int(floor(log2(n)));
        
        if(p%2==0){
            p=p-1;
        }
        int k=1ll<<p;
        //  cout<<"check"<<n<<p<<k<<"\n";
        n-=k;
       
        count++;
    }
    if(n>0 and n<=x){
        count++;
    }
 
   cout<<count<<"\n";
}
    return 0;
}
 