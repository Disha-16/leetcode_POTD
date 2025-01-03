class Solution {
    
    public int findTargetSumWays(int[] nums, int target) {
       return solve(nums.length,0,target,nums);
   
    }
    public int solve(int n,int ind,int target,int[]nums){
        if(ind==n){
            if(target==0)return 1;
            else return 0;
        }
        return solve(n,ind+1,target-nums[ind],nums)+solve(n,ind+1,target+nums[ind],nums);
    }
}
