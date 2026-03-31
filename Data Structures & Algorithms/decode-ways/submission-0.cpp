class Solution {
public:
    string str;
    vector<int> memo;
    int dp(int i){
        if(i==str.size()){
            return 1;
        }
        if(str[i]=='0'){
            return 0;
        }
        if(memo[i]!=-1){
            return memo[i];
        }
        //take one digit
        int ways=dp(i+1);

        //take two digits
        if(i+1<str.size()){
            int num=(str[i]-'0')*10 + (str[i+1]-'0');
            if(num>=10 and num<=26){
                ways+=dp(i+2);
            }
        }
        return memo[i]=ways;

    }
    int numDecodings(string s) {
        str=s;
        memo.assign(str.size(),-1);
        return dp(0);
    }
};
