class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        unordered_map<char,int> umap;
        int i=0,j=0,ans=0,maxFreq=-1;
        while(j<n){
            umap[s[j]]++;
            maxFreq=max(maxFreq,umap[s[j]]);
            while(i<j and (j-i+1)-maxFreq>k){
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
