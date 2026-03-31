class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    int n;
    void backTrack(vector<int>&nums,int target, int start){
        if(target==0){
            result.push_back(path);
            return;
        }
        if(target<0){
            return;
        }
        for(int i=start;i<n;++i){
            path.push_back(nums[i]);
            backTrack(nums,target-nums[i],i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        backTrack(nums,target,0);
        return result;
    }
};
