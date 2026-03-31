class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int dp(int i,int prev, vector<int>& nums){
        if(i==n){
            return 0;
        }
        if(memo[i][prev+1]!=-1){
            return memo[i][prev+1];
        }
        //choice 1: skip nums[i]
        int skip=dp(i+1,prev,nums);

        //choice 2: take nums[i] (if valid)
        int take=0;
        if(prev==-1 or nums[i]> nums[prev]){
            take=1+dp(i+1,i,nums);
        }
        return memo[i][prev+1]=max(skip,take);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memo.assign(n,vector<int>(n+1,-1));
        return dp(0,-1,nums);
    }
};
