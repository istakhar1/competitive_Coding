// { Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Sorting
{
    public static void main (String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        
        while(t-- > 0)
        {
            long n = sc.nextLong();
            long arr[] = new long[(int)n];
            
            for(long i = 0; i < n; i++)
             arr[(int)i] = sc.nextLong();
             
            System.out.println(new Solution().inversionCount(arr, n));
            
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    // arr[]: Input Array
    // N : Size of the Array arr[]
    //Function to count inversions in the array.
    static long inversionCount(long arr[], long n)
    {
        return mergeSort(arr,0,(int)(arr.length-1));
    }
    public static long mergeSort(long arr[],int start,int end){
        long count=0;
        if(start<end){
            int mid=( start +end)/2;
            
            count+=mergeSort(arr,start,mid);
            count+=mergeSort(arr,mid+1,end);
            count+=merge(arr,start,mid,end);
        }
        return count;
    }
    
    public static long merge(long arr[],int left,int mid,int right){
        int n1=mid-left+1;
        int n2=right-mid;
        long leftarr[]=new long[n1]; 
        long rightarr[]=new long[n2];
        for(int i=0;i<n1;i++){
            leftarr[i]=arr[i+left];
        }
        for(int i=0;i<n2;i++){
            rightarr[i]=arr[mid+1+i];
        }
        int i=0,j=0,k=left;
        long sum=0;
        while(i<n1&& j<n2){
            if(leftarr[i]<=rightarr[j]){
                arr[k]=leftarr[i];
                i++;
                k++;
            }
            else{
                arr[k]=rightarr[j];
                j++;
                k++;
                sum+=(long)(mid+1)-(left+i);
            }
        }
        while(i<leftarr.length){
	arr[k++]=leftarr[i++];
}
while(j<rightarr.length){
	arr[k++]=rightarr[j++];
}
return sum;
    }
}