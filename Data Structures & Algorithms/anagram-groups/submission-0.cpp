class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>> umap;
        for(int i=0;i<n;++i){
            string curr=strs[i];
            string copyCurrent=curr;
            sort(copyCurrent.begin(),copyCurrent.end());
            umap[copyCurrent].push_back(curr);
        }
        vector<vector<string>> ans;
        for(auto& [key,value]: umap){
            ans.push_back(value);
        }
        return ans;
    }
};
