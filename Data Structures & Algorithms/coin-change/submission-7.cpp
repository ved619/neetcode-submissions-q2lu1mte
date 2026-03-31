class Solution {
public:
    int INF=1e9;
    int n;
    vector<int> memo;
    int dp(int amount, vector<int>& coins){
        if(amount<0){
            return INF;
        }
        if(amount==0){
            return 0;
        }
        if(memo[amount]!=-1){
            return memo[amount];
        }
        int ans=INF;
        for(int coin: coins){
            ans=min(ans,1+dp(amount-coin,coins));
        }
        return memo[amount]=ans;

    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        memo.assign(amount+1,-1);
        int result=dp(amount,coins);
        if(result==INF){
            return -1;
        }
        return result;
    }
};
