class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i,int canBuy, vector<int>& prices){
        //base case
        if(i>=n){
            return 0;
        }
        if(dp[i][canBuy]!=-1){
            return dp[i][canBuy];
        }
        int profit=0;
        if(canBuy==1){
            int buy=-prices[i]+solve(i+1,0,prices);
            int skip=solve(i+1,1,prices);
            profit=max(buy,skip);
        }
        else{
            int sell=prices[i]+solve(i+2,1,prices);
            int hold=solve(i+1,0,prices);
            profit=max(sell,hold);
        }
        return dp[i][canBuy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        dp.assign(n,vector<int>(2,-1));
        return solve(0,1,prices);
    }
};
