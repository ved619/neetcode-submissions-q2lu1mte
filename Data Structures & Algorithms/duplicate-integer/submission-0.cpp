class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int num:nums){
            umap[num]++;
        }
        for(const auto&[key,value]:umap){
            if(value>1){
                return true;
            }
        }
        return false;
    }
};