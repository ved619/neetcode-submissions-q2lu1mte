class Solution {
public:
    int INF=1e9;
    vector<int> memo;
    int dp(int remainingAmount , vector<int>& coins){
        if(remainingAmount==0){
            return 0;
        }
        if(remainingAmount<0){
            return INF;
        }
        if(memo[remainingAmount]!=-1){
            return memo[remainingAmount];
        }
        int ans=INF;
        for(int coin:coins){
            ans=min(ans,dp(remainingAmount-coin,coins)+1);
        }
        return memo[remainingAmount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount+1,-1);
        int res= dp(amount,coins);
        if(res==INF){
            return -1;
        }
        else{
            return res;
        }
    }
};
