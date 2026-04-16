class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtrack(vector<int>& nums, vector<bool>& used){
        if(path.size()==nums.size()){
            result.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(used[i]) continue;
            if(i>0 and nums[i]==nums[i-1] and !used[i-1]){
                continue;
            }
            //choose
            path.push_back(nums[i]);
            used[i]=true;
            //explore
            backtrack(nums,used);
            //unchoose
            path.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        backtrack(nums,used);
        return result;
    }
};