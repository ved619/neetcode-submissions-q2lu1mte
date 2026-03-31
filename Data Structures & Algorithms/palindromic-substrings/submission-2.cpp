class Solution {
public:
    string str;
    int n;
    vector<vector<int>> memo;
    int dp(int i,int j){
        if(i>=j){
            return 1;
        }
        // if(str[i]!=str[j]){
        //     return 0;
        // }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(str[i]==str[j] and dp(i+1,j-1)){
            return memo[i][j]=1;
        }
        return memo[i][j]=0;
    }
    int countSubstrings(string s) {
        str=s;
        n=s.size();
        int ans=0;
        memo.assign(n,vector<int>(n,-1));
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(dp(i,j)){
                    ++ans;
                }
            }
        }
        return ans;
    }
};
