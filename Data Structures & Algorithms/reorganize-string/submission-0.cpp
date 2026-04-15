class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        for(int i=0;i<26;++i){
            if(freq[i]>0){
                pq.push({freq[i],'a'+i});
            }
        }
        string result="";
        
        while(pq.size()>=2){
            auto [f1,c1]=pq.top(); pq.pop();
            auto [f2,c2]=pq.top(); pq.pop();
            //add both characters
            result+=c1;
            result+=c2;
            f1--;
            f2--;
            if(f1>0) pq.push({f1,c1});
            if(f2>0) pq.push({f2,c2});

        }
        if(!pq.empty()){
            auto [f,c]=pq.top();
            if(f>1) return "";
            result+=c;
        }
        return result;
    }
};