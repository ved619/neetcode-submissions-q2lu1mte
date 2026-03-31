class Solution {
public:
    vector<int> memo;
    int solve(int s){
        if(s<=2){
            return s;
        }
        if(memo[s]!=-1){
            return memo[s];
        }
        return memo[s]=solve(s-1)+solve(s-2);
    }
    int climbStairs(int n) {
       memo.assign(n+1,-1);
       return solve(n);
    }
};
