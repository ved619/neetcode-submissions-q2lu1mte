class Solution {
public:
    vector<vector<int>> memo;
    int n;
    int dp(int i, int prev, vector<int>& nums){
        if(i==n){
            return 0;
        }
        if(memo[i][prev+1]!=-1){
            return memo[i][prev+1];
        }
        int take=0;
        if(nums[i]>nums[prev] or prev==-1){
            take=1+dp(i+1,i,nums);
        }
        //skip
        int skip=dp(i+1,prev,nums);
        return memo[i][prev+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memo.assign(n,vector<int>(n+1,-1));   
        return dp(0,-1,nums);
    }
};
