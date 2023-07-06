class Solution {
  public static void permut(List<Integer> a,int idx,List<List<Integer>> value){
      if(idx==a.size()){
          value.add(new ArrayList<>(a));// remember this line create new list every time otherwise u will get same array every time;
          return;
      }
      for(int i=idx;i<a.size();i++){
          Collections.swap(a,i,idx);
          permut(a,idx+1,value);
          Collections.swap(a,i,idx);
         
      }
      return;
  }
    
    public List<List<Integer>> permute(int[] nums) {
     List<List<Integer>> value=new ArrayList<>();
      List<Integer> a=new ArrayList<>();
        for(int i=0;i<nums.length;i++)a.add(nums[i]);
        permut(a,0,value);
        return value;
         
    }
}