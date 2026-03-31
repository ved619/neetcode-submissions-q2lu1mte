class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[left]==nums[mid] and nums[mid]==nums[right]){
                left++;
                right--;
            }
            //if left-half is sorted
            if(nums[left]<=nums[mid]){
                if(target>=nums[left] and target<nums[mid]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            //if right-half is sorted
            else{
                if(target>nums[mid] and target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return false;
    }
};