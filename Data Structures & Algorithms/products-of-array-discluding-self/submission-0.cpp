class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        //fillup prefix array first
        int prodPrefix=1;
        for(int i=0;i<n;++i){
            prefix[i]=prodPrefix;
            prodPrefix*=nums[i];
        }
        int prodSuffix=1;
        for(int i=n-1;i>=0;--i){
            suffix[i]=prodSuffix;
            prodSuffix*=nums[i];
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;++i){
            ans[i]=suffix[i]*prefix[i];
        }
        return ans;
    }
};
