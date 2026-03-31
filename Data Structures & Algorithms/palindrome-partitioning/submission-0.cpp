class Solution {
public:
    vector<string> path;
    vector<vector<string>> result;
    bool isPalindrome(string& s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    void backtrack(int start, string& s){
        if(start==s.length()){
            result.push_back(path);
            return;
        }
        for(int end=start;end<s.size();++end){
            if(isPalindrome(s,start,end)){
                path.push_back(s.substr(start,end-start+1));
                backtrack(end+1,s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(0,s);
        return result;
    }
};
