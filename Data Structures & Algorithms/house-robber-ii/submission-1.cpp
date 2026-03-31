class Solution {
public:
    vector<int> memo;
    int dp(int index, int end, vector<int>&nums){
        if(index>end){
            return 0;
        }
        if(memo[index]!=-1){
            return memo[index];
        }
        int skip=dp(index+1,end,nums);
        int take=nums[index]+dp(index+2,end,nums);
        return memo[index]=max(skip,take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        memo.assign(n,-1);
        int first=dp(0,n-2,nums);
        memo.assign(n,-1);
        int second=dp(1,n-1,nums);
        return max(first,second);
    }
};
