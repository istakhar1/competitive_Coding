// https://www.codechef.com/MAY222C/problems/DPOLY

/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-- > 0){
		    int n=sc.nextInt();
		    int count=0;
		    int ans=0;
		    while(n-- > 0){
		        int x=sc.nextInt();
		        if(x!=0){
		            ans=count;
		            
		        }
		        
		        count++;
		        
		    }
		    System.out.println(ans);
		}
		
	}
}
