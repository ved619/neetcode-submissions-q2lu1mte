class Solution {
public:
    vector<vector<int>> memo;
    bool isPal(const string& s, int i,int j){
        if(i>=j){
            return true;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(s[i]!=s[j]){
            return memo[i][j]=0;
        }
        return memo[i][j]=isPal(s,i+1,j-1);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        memo.assign(n,vector<int>(n,-1));
        int bestStart=0;
        int bestLen=1;  
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(isPal(s,i,j)){
                    int len=j-i+1;
                    if(len>bestLen){
                        bestLen=len;
                        bestStart=i;
                    }
                }
            }
        }
        return s.substr(bestStart,bestLen);
    }
};
