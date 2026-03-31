class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        int sum=0,result=INT_MAX;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                result=min(result,j-i+1);
                sum-=nums[i];
                ++i;
            }
            // result=min(result,j-i+1);
            ++j;
        }
        if(result==INT_MAX){
            return 0;
        }
        return result;
    }
};