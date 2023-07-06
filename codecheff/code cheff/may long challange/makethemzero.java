// https://www.codechef.com/MAY222C/problems/MAKEZERO
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
		    int xorsum=0;
		    for(int i=0;i<n;i++){
		        int value=sc.nextInt();
		        xorsum  = xorsum | value;
		    }
		    int ans=0;
		    while(xorsum > 0){
		       ans += xorsum & 1;
                xorsum >>= 1;
		    }
		    System.out.println(ans);
		}
	}
}
