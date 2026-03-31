class Solution {
public:
    int n,target_,offset;
    vector<vector<int>> dp;
    int solve(int i, int currSum, vector<int>& nums){
        if(i==n){
            if(currSum==target_){
                return 1;
            }
            return 0;
        }
        int idx=currSum+offset;
        if(dp[i][idx]!=INT_MIN){
            return dp[i][idx];
        }
        //choices
        int add=solve(i+1,currSum+nums[i],nums);
        int sub=solve(i+1,currSum-nums[i],nums);
        return dp[i][idx]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        target_=target;
        n=nums.size();
        int totalSum=0;
        for(int x:nums)totalSum+=x;
        offset=totalSum;
        dp.assign(n,vector<int>(2*totalSum+1,INT_MIN));
        return solve(0,0,nums);
    }
};
