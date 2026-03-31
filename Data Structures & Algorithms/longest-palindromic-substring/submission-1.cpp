class Solution {
public:
    string str;
    vector<vector<int>> memo;

    bool dp(int l,int r){
        if(l>=r){
            return true;
        }
        if(memo[l][r]!=-1){
            return memo[l][r];
        }
        if(str[l]==str[r] and dp(l+1,r-1)){
            return memo[l][r]=true;
        }
        return memo[l][r]=false;
    }
    string longestPalindrome(string s) {
        str=s;
        int n=s.size();
        memo.assign(n,vector<int>(n,-1));

        int start=0;
        int maxLen=0;
        for(int l=0;l<n;++l){
            for(int r=l;r<n;++r){
                if(dp(l,r)){
                    if(r-l+1>maxLen){
                        start=l;
                        maxLen=r-l+1;
                    }
                }
            }
        }
        return str.substr(start,maxLen);
    }
};
