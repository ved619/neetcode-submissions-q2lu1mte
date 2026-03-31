class Solution {
public:
    int INF=1e9;
    vector<int> memo;

    int dp(vector<int>& coins, int remAmount){
        if(remAmount==0){
            return 0;
        }
        if(remAmount<0){
            return INF;
        }
        if(memo[remAmount]!=-1){
            return memo[remAmount];
        }
        int ans=INF;
        for(int coin: coins){
            ans= min(ans,dp(coins,remAmount-coin)+1);
        }
        return memo[remAmount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount+1,-1);
        int res=dp(coins,amount);
        return (res>=INF)? -1: res;
    }
};
