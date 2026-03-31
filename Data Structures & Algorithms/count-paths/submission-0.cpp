class Solution {
public:
    int mx, nx;
    vector<vector<int>> memo;
    int dp(int r, int c){
        if(r>=mx or c>=nx){
            return 0;
        }
        if(r==mx-1 and c==nx-1){
            return 1;
        }
        if(memo[r][c]!=-1){
            return memo[r][c];
        }
        return memo[r][c]=dp(r+1,c)+dp(r,c+1);
    }
    int uniquePaths(int m, int n) {
        mx=m;
        nx=n;
        memo.assign(m,vector<int>(n,-1));
        return dp(0,0);
    }
};
