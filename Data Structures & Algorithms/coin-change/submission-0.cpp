class Solution {
public: 
    int INF=1e9;
    vector<int> memo;
    int solve(int rem, vector<int>& coins){
        //base cases
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
        //try picking each coin
        for(int coin:coins){
            int res=solve(rem-coin,coins);
            if(res!=INF){
                ans=min(ans,1+res);
            }
        }
        memo[rem]=ans;
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount+1,-1);
        int res=solve(amount,coins);
        return (res==INF)? -1: res;
    }
};
