class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> u1;
        unordered_map<char,int> u2;
        int len1=s1.length(),len2=s2.length();
        //freq array of s1
        for(char s: s1){
            u1[s]++;
        }
        int i=0,j=0;
        while(j<len2){
            u2[s2[j]]++;
            while(j-i+1>len1){
                u2[s2[i]]--;
                if(u2[s2[i]]==0){
                    u2.erase(s2[i]);
                }
                ++i;
            }
            if(u1==u2){
                return true;
            }
            ++j;
        }
        return false;
    }
};
