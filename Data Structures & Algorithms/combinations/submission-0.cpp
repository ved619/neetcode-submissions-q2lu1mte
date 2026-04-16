class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backtrack(int index, int n, int k){
        if(path.size()==k){
            result.push_back(path);
            return;
        }
        for(int i=index;i<=n;++i){
            //choose
            path.push_back(i);
            //recurse
            backtrack(i+1,n,k);
            //popback
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(1,n,k);
        return result;
    }
};