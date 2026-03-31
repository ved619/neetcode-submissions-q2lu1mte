class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    int n;
    void backTrack(int index,vector<int>& nums){
        result.push_back(path);
        if(index==n){
            return;
        }
        for(int i=index;i<n;++i){
            path.push_back(nums[i]);
            backTrack(i+1,nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        backTrack(0,nums);
        return result;
    }
};
