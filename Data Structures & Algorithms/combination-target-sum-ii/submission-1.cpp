class Solution {
public:
    int n;
    vector<int> current;
    vector<vector<int>> result;
    vector<int> path;
    void backTrack(int index, vector<int>& candidates, int target){
        if(target==0){
            result.push_back(current);
        }
        if(target<0){
            return;
        }
        for(int i=index;i<n;++i){
            if(i>index and candidates[i]==candidates[i-1]){
                continue;
            };
            current.push_back(candidates[i]);
            backTrack(i+1,candidates,target-candidates[i]);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        n=candidates.size();
        backTrack(0,candidates,target);
        return result;
    }
};
