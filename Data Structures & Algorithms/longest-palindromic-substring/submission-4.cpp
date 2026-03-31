class Solution {
public:
    vector<vector<int>> memo;
    bool dp(int left, int right, string& s){
        if(left>=right){
            return true;
        }
        if(memo[left][right]!=-1){
            return memo[left][right];
        }
        if(s[left]==s[right] and dp(left+1,right-1,s)){
            return memo[left][right]=1;
        }
        return memo[left][right]=0;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        memo.assign(n,vector<int>(n,-1));
        int maxLen=0;
        int start=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(dp(i,j,s)){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};
