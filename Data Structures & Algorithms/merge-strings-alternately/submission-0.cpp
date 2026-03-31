class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int a=0,b=0;
        string result="";
        while(a<word1.length() and b<word2.length()){
            result+=word1[a];
            result+=word2[b];
            ++a;
            ++b;
        }
        if(a<word1.length()){
            while(a<word1.length()){
                result+=word1[a];
                ++a;
            }
        }
        else if(b<word2.length()){
            while(b<word2.length()){
                result+=word2[b];
                ++b;
            }
        }
        return result;
    }
};