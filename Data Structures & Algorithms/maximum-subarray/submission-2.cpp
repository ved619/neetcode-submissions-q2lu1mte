class Solution {
public:
    vector<int> memo;
    int dp(int i, vector<int>& nums){
        if(i==0){
            return nums[0];
        }
        if(memo[i]!=INT_MIN){
            return memo[i];
        }
        return memo[i]=max(nums[i],nums[i]+dp(i-1,nums));
    }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        memo.assign(n,INT_MIN);
        int ans=nums[0];
        for(int i=0;i<n;++i){
            ans=max(ans,dp(i,nums));
        }
        return ans;
    }
};
