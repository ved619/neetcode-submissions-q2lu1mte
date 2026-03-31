class Solution {
public:
    int n;
    vector<int> memo;
    int dp(int i, vector<int>& cost){
        if(i>=n){
            return 0;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        //one-step
        int takeOne=cost[i]+dp(i+1,cost);
        int takeTwo=cost[i]+dp(i+2,cost);
        return memo[i]=min(takeOne,takeTwo);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        memo.assign(n,-1);
        int startFromZero=dp(0,cost);
        memo.assign(n,-1);
        int startFromOne=dp(1,cost);
        return min(startFromZero,startFromOne);
    }
};
