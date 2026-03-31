class Solution {
public:
    int n,m;
    vector<vector<int>> memo;
    int dp(int i,int j, string& s1, string& s2){
        if(i==n or j==m){
            return 0;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(s1[i]==s2[j]){
            return memo[i][j]=1+dp(i+1,j+1,s1,s2);
        }
        return memo[i][j]=max(dp(i+1,j,s1,s2),dp(i,j+1,s1,s2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n=text1.size();
        m=text2.size();
        memo.assign(n,vector<int>(m,-1));
        return dp(0,0,text1,text2);
    }
};
