class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int ans=0;
        for(int i=0;i<nums.size();++i){
            int tempAns=0;
            if(nums[i]==1){
                for(int j=i;j<nums.size();++j){
                    if(nums[j]==nums[i]){
                        ++tempAns;
                    }
                    else{
                        break;
                    }
                }
                ans=max(ans,tempAns);
            }
        }
        return ans;
    }
};