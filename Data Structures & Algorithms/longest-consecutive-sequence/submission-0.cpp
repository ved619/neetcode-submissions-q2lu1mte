class Solution {
public:
    unordered_set<int> st;
    unordered_map<int,int> memo;
    int dp(int x){
        if(memo.count(x)){
            return memo[x];
        }
        if(!st.count(x+1)){
            return memo[x]=1;
        }
        return memo[x]=1+dp(x+1);
    }
    int longestConsecutive(vector<int>& nums) {
        for(int num:nums){
            st.insert(num);
        }
        int ans=0;
        for(int x: st){
            ans=max(ans,dp(x)); 
        }
        return ans;
    }
};
