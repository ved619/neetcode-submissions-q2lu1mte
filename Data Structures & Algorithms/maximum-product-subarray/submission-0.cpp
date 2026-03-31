class Solution {
public:
    vector<pair<int,int>> memo;
    vector<bool> visited;
    int ans;
    pair<int,int> solve(int i,vector<int>& nums){
        if(visited[i]){
            return memo[i];
        }
        visited[i]=true;
        if(i==0){
            memo[i]={nums[0],nums[0]};
            ans=max(ans,nums[0]);
            return memo[i];
        }
        auto [prevMax, prevMin]=solve(i-1,nums);
        int x=nums[i];
        int currMax=max({x, x*prevMax, x*prevMin});
        int currMin=min({x, x*prevMax, x*prevMin});
        ans=max(ans,currMax);
        memo[i]={currMax,currMin};
        return memo[i];
    }
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        memo.resize(n);
        visited.resize(n,false);
        ans=nums[0];
        solve(n-1,nums);
        return ans;
    }
};
