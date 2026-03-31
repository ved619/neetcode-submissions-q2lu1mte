class Solution {
public:
    vector<int> memo;
    int dp(int index,vector<int>& nums){
        if(index>=nums.size()){
            return 0;
        }
        if(memo[index]!=-1){
            return memo[index];
        }
        int take=nums[index]+dp(index+2,nums);
        int skip=dp(index+1,nums);
        return memo[index]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        memo.assign(nums.size(),-1);
        return dp(0,nums);
    }
};
