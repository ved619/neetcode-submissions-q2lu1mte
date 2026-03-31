class Solution {
public:
    vector<vector<int>> memo;
    int n;
    int dp(int index, int prev, vector<int>& nums){
        if(index==n){
            return 0;
        }
        if(memo[index][prev+1]!=-1){
            return memo[index][prev+1];
        }
        //skip
        int skip=dp(index+1,prev,nums);
        //take
        int take=0;
        if(prev==-1 or nums[index]>nums[prev]){
            take=1+dp(index+1,index,nums);
        }
        return memo[index][prev+1]=max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memo.assign(n,vector<int>(n+1,-1));
        return dp(0,-1,nums);
    }
};
