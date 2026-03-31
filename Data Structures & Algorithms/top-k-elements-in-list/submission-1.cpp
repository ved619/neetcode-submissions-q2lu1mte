class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int& num:nums){
            umap[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto& [key,value]: umap){
            pq.push({value,key});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            auto& [x,y]=pq.top();
            ans.push_back(y);
            pq.pop();
        }
        return ans;
    }
};
