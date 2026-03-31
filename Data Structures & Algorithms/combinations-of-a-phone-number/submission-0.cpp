class Solution {
public:
    string path="";
    vector<string> result;
    void backtrack(int index, unordered_map<char,string>& umap, string& digits){
        if(index==digits.length()){
            result.push_back(path);
            return;
        }
        char currDigit=digits[index];
        string letters=umap[currDigit];
        for(int i=0;i<letters.length();++i){
            path.push_back(letters[i]);
            backtrack(index+1,umap,digits);
            path.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return result;
        }
        unordered_map<char,string> umap;
        umap['2']="abc";
        umap['3']="def";
        umap['4']="ghi";
        umap['5']="jkl";
        umap['6']="mno";
        umap['7']="pqrs";
        umap['8']="tuv";
        umap['9']="wxyz";
        backtrack(0,umap,digits);
        return result;
    }
};
