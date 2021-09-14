class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new LinkedList<>(); 
        
        int i=0;
        int n=nums.length;
        Arrays.sort(nums);
        while(i<n-2){
             if (i > 0 && nums[i] == nums[i - 1]) {   
                 // skip same result
            ++i;
        continue;
        }
            int j=i+1,k=n-1;
            int val=-nums[i];
            while(j<k){
                    if(nums[j]+nums[k]== val &&(i!=j)&&(j!=k)&&(k!=i))
                    {    
                    res.add(Arrays.asList(nums[i], nums[j], nums[k])); 
                        j++;
                        k--;
                         while (j < k && nums[j] == nums[j - 1]) j++;  
                         while (j < k && nums[k] == nums[k + 1]) k--; 
                    }
                    else if(nums[j]+nums[k] < val)
                    {
                        j++;
                    }
                    else{
                          k--;      
                    }
            }
            i++;
        }
        
        
        return res;
    }
}