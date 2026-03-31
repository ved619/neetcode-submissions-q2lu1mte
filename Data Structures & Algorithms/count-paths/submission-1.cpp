class Solution {
public:
    vector<vector<int>> memo;
    int noRows, noCols;
    int dp(int row, int col){
        //base case
        if(row<0 or row>=noRows or col<0 or col>=noCols){
            return 0;
        }
        if(row==noRows-1 and col==noCols-1){
            return 1;
        }
        if(memo[row][col]!=-1){
            return memo[row][col];
        }
        //go down
        int goDown=dp(row+1,col);
        int goRight=dp(row,col+1);
        return memo[row][col]=goDown+goRight;
    }
    int uniquePaths(int m, int n) {
        noRows=m;
        noCols=n;
        memo.assign(noRows,vector<int>(noCols,-1));
        return dp(0,0);
    }
};
