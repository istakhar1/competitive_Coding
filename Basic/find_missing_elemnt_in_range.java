/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef 
{
   
    
    
	public static void main (String[] args) throws java.lang.Exception
	{
	  Scanner inputTaker =new Scanner(System.in);
	  int n=inputTaker.nextInt();
	  int a[]=new int[n];
	  for(int i=0;i<n;i++)a[i]=inputTaker.nextInt();
	  Arrays.sort(a);
	  int start=a[0];
	  int end=a[n-1];
	  for(int i=start;i<=end;i++){
	      if(!present(a,0,n-1,i)){
	          System.out.print(i+" ");
	      }
	  }
	  
	      
	           
	}
	public static boolean present(int a[],int start,int end,int key){
	    while(start<=end){
	        int mid=start +(end-start)/2;
	        if(a[mid]==key){
	            return true;
	        }
	        else if(a[mid]>key){
	            end=mid-1;
	        }
	        else{
	            start=mid+1;
	        }
	    }
	    return false;
	}
	

}


