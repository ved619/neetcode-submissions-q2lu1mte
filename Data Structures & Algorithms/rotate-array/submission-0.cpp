class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> copy=nums;
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(i+k<=n-1){
                nums[i+k]=copy[i];
            }
            else{
                int newIndex=(i+k)%n;
                nums[newIndex]=copy[i];
            }
        }
    }
};