class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int i=0,j=0,n=nums.size();
        while(j<n){
            if(st.count(nums[j])){
                return true;
            } 
            st.insert(nums[j]);
            while(j-i>=k){
                st.erase(nums[i]);
                ++i;
            }
            ++j;
        }
        return false;
    }
};