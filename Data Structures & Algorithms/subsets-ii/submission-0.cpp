class Solution {
public:
    int n;
    vector<vector<int>> result;
    vector<int> curr;
    void backTrack(int index, vector<int>& nums){
        result.push_back(curr);
        if(index==n){
            return;
        }
        for(int i=index;i<n;++i){
            if(i>index and nums[i]==nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            backTrack(i+1,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        backTrack(0,nums);
        return result;
    }
};
