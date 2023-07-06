// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*; 

class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0){
            String s = read.readLine();
            Solution ob = new Solution();
            
            System.out.println(ob.cuts(s));
        }
    } 
} 
// } Driver Code Ends


//User function Template for Java

class Solution{
    public static boolean powerFive(long n){
        if(n<125){
            return (n==1||n==5||n==25);
        }
        if(n%125!=0)
        {
            return false;
        }else{
            return powerFive(n/125);
        }
    }
    
    public static long number(String s,int i,int j){
        long res=0;
        for(int x=i;x<j;x++){
            res = res*2 +(s.charAt(x)-'0');
        }
        return res;
    }
    static int cuts(String s)
    {
        // code here
        int n=s.length();
        int dp[]=new int[n+1];
        Arrays.fill(dp,n+1);
        dp[0]=0;
        for(int i=1;i<=s.length();i++){
            if(s.charAt(i-1)=='0')
                continue;
                
            for(int j=0;j<i;j++){
                if(s.charAt(j)=='0')
                    continue;
                    
                long num=number(s,j,i);
                
                if(!powerFive(num))
                    continue;
                    
                dp[i]=Math.min(dp[i],dp[j]+1);    
                
            }    
        }
        return (dp[n]<(n+1))?dp[n]:-1;
    
    }
}
