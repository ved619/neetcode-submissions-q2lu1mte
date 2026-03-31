class Solution {
public:
    unordered_set<string> dict;
    vector<int> memo;
    bool solve(int i, string& s){
        if(i==s.length()){
            return true;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        for(int len=1;i+len<=s.length();++len){
            string stringPart=s.substr(i,len);
            if(dict.count(stringPart)){
                if(solve(i+len,s)){
                    memo[i]=1;
                    return true;
                }
            }
        }
        memo[i]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dict=unordered_set<string>(wordDict.begin(),wordDict.end());
        memo.assign(s.length(),-1);
        return solve(0,s);
    }
};
