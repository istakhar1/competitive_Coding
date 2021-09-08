/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
public static void swap(int[] arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    
     public static int partition(int arr[],int low , int high){
         int pivot=arr[high];
         int i=low-1;
         for(int j=low;j<=high-1;j++){
             if(arr[j]<pivot){
                 i++;
                 swap(arr,i,j);
             }
         }
         swap(arr,(i+1),high);
         return (i+1);
     }
     
    public static void quick(int a[], int low ,int high){
        if(low<high){
            int pivot=partition(a,low,high);
            
            quick(a,low,pivot-1);
            quick(a,pivot+1,high);
            
        }
      
    }
	public static void main (String[] args) throws java.lang.Exception
	{
		 Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++)a[i]=sc.nextInt();
		quick(a,0,n-1);
		for(int i=0;i<n;i++){
		    System.out.print(a[i]+" ");
		}
	}
}
