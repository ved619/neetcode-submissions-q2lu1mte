class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> umap;
        for(int num:nums){
            umap[num]++;
        }
        for(int i=0;i<=n;++i){
            if(umap.find(i)==umap.end()){
                return i;
            }
        }
        return -1;
    }
};
