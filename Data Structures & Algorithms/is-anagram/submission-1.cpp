class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sV(26,0);
        vector<int> tV(26,0);
        for(char c:s){
            sV[c-'a']++;
        }
        for(char c:t){
            tV[c-'a']++;
        }
        if(sV==tV)return true;
        return false;
    }
};
