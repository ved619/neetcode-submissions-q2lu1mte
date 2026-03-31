class Solution {
public:
    int n,m;
    vector<vector<int>> memo;
    bool dfs(int i,int j,string &s1, string &s2, string &s3){
        //both strings used completely
        if(i==n and j==m){
            return true;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        int k=i+j;
        bool ans=false;
        //choice 1: take from s1
        if(i<n and s1[i]==s3[k]){
            ans=dfs(i+1,j,s1,s2,s3);
        }
        if(!ans and j<m and s2[j]==s3[k]){
            ans=dfs(i,j+1,s1,s2,s3);
        }
        return memo[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size();
        m=s2.size();
        if(n+m!=s3.size()){
            return false;
        }
        memo.assign(n+1,vector<int>(m+1,-1));
        return dfs(0,0,s1,s2,s3);
    }
};
