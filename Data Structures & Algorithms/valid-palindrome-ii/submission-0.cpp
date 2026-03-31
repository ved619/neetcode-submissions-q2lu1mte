class Solution {
public:
    bool isPalindrome(int left,int right, string s){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        int flag=0;
        while(i<j){
            if(s[i]==s[j]){
                ++i;
                --j;
            }
            else{
                return isPalindrome(i+1,j,s) or isPalindrome(i,j-1,s);
            }
        }
        return true;
    }
};