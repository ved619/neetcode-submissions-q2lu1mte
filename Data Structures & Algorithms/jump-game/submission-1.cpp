class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int flag=n-1;
        for(int i=n-1;i>=0;--i){
            if(i+nums[i]>=flag){
                flag=i;
            }
        }
        if(flag==0){
            return true;
        }
        return false;
    }
};
