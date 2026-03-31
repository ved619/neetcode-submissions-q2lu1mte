class Solution {
public:
    vector<vector<int>> memo;
    string str;
    int dp(int left,int right){
        if(left>=right){
            return 1;
        }
        if(memo[left][right]!=-1){
            return memo[left][right];
        }
        if(str[left]==str[right] and dp(left+1,right-1)){
            return memo[left][right]=1;
        }
        return memo[left][right]=0;
    }
    string longestPalindrome(string s) {
        str=s;
        memo.assign(s.size(),vector<int>(s.size(),-1));
        int start=0;
        int maxLength=0;
        for(int i=0;i<s.size();++i){
            for(int j=i;j<s.size();++j){
                if(dp(i,j)){
                    if(j-i+1>maxLength){
                        maxLength=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return str.substr(start,maxLength);
    }
};
