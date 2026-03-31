class Solution {
public:
    const int INF=1e9;
    vector<int> memo;
    int dp(int rem, vector<int>& coins){
        if(rem==0){
            return 0;
        }
        if(rem<0){
            return INF;
        }
        if(memo[rem]!=-1){
            return memo[rem];
        }
        int ans=INF;
        for(int coin:coins){
            ans=min(ans,1+dp(rem-coin,coins));
        }
        return memo[rem]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount +1,-1);
        int res=dp(amount,coins);
        return (res==INF) ? -1 : res;
    }
};
