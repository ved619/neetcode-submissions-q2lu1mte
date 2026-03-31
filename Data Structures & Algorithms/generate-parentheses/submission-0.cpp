class Solution {
public:
    void backTrack(int open, int close, int n, string& current, vector<string>& result){
        if(current.length()==2*n){
            result.push_back(current);
            return;
        }
        if(open<n){
            current.push_back('(');
            backTrack(open+1,close,n,current, result);
            current.pop_back();
        }
        if(close<open){
            current.push_back(')');
            backTrack(open, close+1,n,current, result);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backTrack(0,0,n,current, result);
        return result;
    }
};
