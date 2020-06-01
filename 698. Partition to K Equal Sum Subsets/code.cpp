class Solution {
public:
    
    bool solve(vector<int> &nums,int startIteration,vector<bool> used,int k,int curr,int target){
        if (k == 1){
            return true;
        }
        if (curr == target){
            return solve(nums,0,used,k-1,0,target);
        }
        for (int i=startIteration;i<nums.size();i++){
            if (!used[i]){
                used[i] = true;
                if (solve(nums,i+1,used,k,curr+nums[i],target)){
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for (int i=0;i<nums.size();i++){
            total += nums[i];
        }
        if (k == 0 || total%k != 0){
            return false;
        }
        vector<bool> used(nums.size(),false);
        return solve(nums,0,used,k,0,total/k);
    }
};
