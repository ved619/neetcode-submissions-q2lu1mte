class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i,int rem, vector<int>& coins){
        if(rem==0){
            return 1;
        }
        if(i==n or rem<0){
            return 0;
        }
        if(dp[i][rem]!=-1){
            return dp[i][rem];
        }
        int take=solve(i,rem-coins[i],coins);
        int skip=solve(i+1,rem,coins);
        return dp[i][rem]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return solve(0,amount,coins);
    }
};
