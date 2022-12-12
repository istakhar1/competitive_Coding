#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
 

// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int queryOnSegmentTree(int *segTree, int start , int end, int treeIndex , int left , int right){
    if(start > right || end < left){
        return 0;
    }
    if(start>=left && end<=right){
        return segTree[treeIndex];
    }
    int mid = (start +end)/2;
    int leftValue = queryOnSegmentTree(segTree,start, mid, 2*treeIndex,left,right);
    int rightValue = queryOnSegmentTree(segTree,mid+1, end, 2*treeIndex+1,left, right);

    return leftValue+rightValue; 

}

void buildSegmentTree(int *arr, int *segTree,int start , int end, int treeIndex){
    if(start==end){
        segTree[treeIndex]= arr[start];
        return ;
    }
    int mid = (start + end)/2;
    buildSegmentTree(arr,segTree,start,mid,2*treeIndex);
    buildSegmentTree(arr,segTree,mid+1,end,2*treeIndex+1);

    segTree[treeIndex] = segTree[2*treeIndex] + segTree[2*treeIndex+1];
}


 
void c_p_c()
{   
    int mod= 998244353;
    int t;
    cin>>t;
    while(t--){
              int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++)cin>>arr[i];
    
        int *segTree = new int[4*n];
        buildSegmentTree(arr,segTree,0,n-1,1);
    
        //find rage sum from array 
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int val = queryOnSegmentTree(segTree,0,n-1,1,i,j);
                int sq = (val%mod * val%mod)%mod;
                int qu = (sq%mod * val%mod)%mod;
                
                ans = (ans%mod + qu%mod)%mod;
            }
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