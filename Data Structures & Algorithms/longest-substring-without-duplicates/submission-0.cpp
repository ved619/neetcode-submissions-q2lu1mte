class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0,j=0;
        unordered_map<char,int> umap;
        int ans=0;
        while(j<n){
            umap[s[j]]++;
            while(umap[s[j]]>1){
                umap[s[i]]--;
                if(umap[s[i]]==0){
                    umap.erase(s[i]);
                }
                ++i;
            }
            ans=max(ans,j-i+1);
            ++j;
        }
        return ans;
    }
};
