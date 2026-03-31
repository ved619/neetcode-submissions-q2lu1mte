class Solution {
public:
    vector<vector<int>> memo;
    string str;
    int n;
    bool dp(int l,int r){
        if(l>=r){
            return true; 
        }
        if(memo[l][r]!=-1){
            return memo[l][r];
        }
        if(str[l]==str[r] and dp(l+1,r-1)){
            return memo[l][r]=1;
        }
        return memo[l][r]=0;

    }
    string  longestPalindrome(string s) {
        n=s.size();
        str=s;
        memo.assign(n,vector<int>(n,-1));
        int maxLen=1;
        int start=0;
        for(int l=0;l<n;++l){
            for(int r=l;r<n;++r){
                if(dp(l,r) and (r-l+1>maxLen)){
                    maxLen=r-l+1;
                    start=l;
                }
            }
        }
        return str.substr(start,maxLen);
    }
};
