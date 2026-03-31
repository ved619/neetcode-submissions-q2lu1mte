class Solution {
public:
    vector<int> memo;
    int INF=1e9;
    int dp(int amount,vector<int>& coins){
        if(amount==0){ 
            return 0;
        }
        if(amount<0){
            return INF;
        }
        if(memo[amount]!=-1){
            return memo[amount];
        }
        int ans=INF;
        for(int coin:coins){
            ans=min(ans,dp(amount-coin,coins)+1);
        }
        return memo[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount+1,-1);
        int result=dp(amount,coins);
        if(result==INF){
            return -1;
        }
        return result;
    }
};
