class Solution {
public:
    vector<int> memo;
    int n;
    int dp(int i, vector<int>& nums){
        if(i>=n){
            return 0;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        //skip
        return memo[i]=max(dp(i+1,nums), nums[i] + dp(i+2,nums));

    }
    int rob(vector<int>& nums) {
        n=nums.size();
        memo.assign(n,-1);
        return dp(0,nums);
    }
};
