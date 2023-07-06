// https://www.codechef.com/MAY222C/problems/XOR_PAL

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool ispalindrom(string s,int n){
    for(int i=0,j=n-1;i<n/2;i++,j--){
        if(s[i]!=s[j]) return false;
    }
    
    return true;
}

int main() {
	int t;cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    string s;
	    cin>>s;
	    int count=0;
	    for(int i=0,j=n-1;i<n/2;i++,j--){
	        if(s[i]!=s[j]){
	            
	           count++;
	        }
	    }
	    if(count%2!=0){
	      cout<< (count/2) + 1<<"\n";  
	    }
	    else{
	        cout<< count/2<<"\n";
	    }
	    
	}
	return 0;
}
