class Solution {
public:
    int n;
    vector<int> memo;
    int solve(int i, vector<int>& nums){
        if(i>=n-1){
            return 0;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        int ans=INT_MAX;
        for(int jump=1;jump<=nums[i];++jump){
            int next=i+jump;
            if(next<n){
                int res=solve(next,nums);
                if(res!=INT_MAX){
                    ans=min(ans,1+res);
                }
            }
        }
        return memo[i]=ans;
    }
    int jump(vector<int>& nums) {
        n=nums.size();
        memo.assign(n,-1);
        return solve(0,nums);
    }
};
