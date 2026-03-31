class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    vector<int> used;
    int n;
    void backTrack(vector<int>& nums){
        if(current.size()==n){
            result.push_back(current);
            return;
        }
        for(int i=0;i<n;++i){
            //choose
            if(used[i]) continue;
            used[i]=true;
            current.push_back(nums[i]);
            backTrack(nums);
            current.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        used.resize(n,false);
        backTrack(nums);
        return result;
    }
};
