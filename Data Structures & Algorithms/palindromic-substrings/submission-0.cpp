class Solution {
public:

    vector<vector<int>> memo;
    int n;
    bool isPalindrome(int l,int r, string& s){
        if(l>=r){
            return true;
        }
        if(memo[l][r]!=-1){
            return memo[l][r];
        }
        if(s[l]==s[r]){
            return memo[l][r]=isPalindrome(l+1, r-1,s);
        }
        else{
            return memo[l][r]=false;
        }
        
    }
    int countSubstrings(string s) {
        n=s.size();
        memo.assign(n,vector<int>(n,-1));
        int count=0;
        for(int i=0;i<n;++i){
            for(int j=i;j<n;++j){
                if(isPalindrome(i,j,s)){
                    ++count;
                }
            }
        }
        return count;
    }
};
