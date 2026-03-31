class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n;
        n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-2;++i){
            int current=nums[i];
            int left=i+1;
            int right=n-1;
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            while(left<right){
                int sum=nums[left]+nums[right]+current;
                if(sum==0){
                    ans.push_back({current,nums[left],nums[right]});
                    while(left<right and nums[left]==nums[left+1]){
                        ++left;
                    }
                    while(left<right and nums[right]==nums[right-1]){
                        --right;
                    }
                    ++left;
                    --right;
                }
                else if(sum<0){
                    ++left;
                }
                else{
                    --right;
                }
            }
        }
        return ans;
    }
};
