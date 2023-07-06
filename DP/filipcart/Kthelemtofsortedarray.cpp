class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0,j=0;
        int prev=-1,count=0;
        while(i<n&&j<m){
            if(count==k){
                break;
            }
            if(arr1[i]<arr2[j]){
                prev=arr1[i];
                ++i;
            }else{
                prev=arr2[j];
                ++j;
            }
            ++count;
        }
        if(count<k){
            while(i<n&&count<k){
                prev=arr1[i++];
                ++count;
                
            }
            while(j<m&&count<k){
                prev=arr2[j++];
                ++count;
            }
        }
        return prev;
    }
};
