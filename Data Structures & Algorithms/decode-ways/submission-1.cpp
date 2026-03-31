class Solution {
public:
    vector<int> memo;
    int n;
    string str;
    int dp(int index){
        if(index==n){
            return 1;
        }
        if(str[index]=='0'){
            return 0;
        }
        if(memo[index]!=-1){
            return memo[index];
        }
        //take one digit
        int ways=dp(index+1);
        //take 2 digits
        if(index+1<n){
            int num=(str[index]-'0')*10+(str[index+1]-'0');
            if(num>=10 and num<=26){
                ways+=dp(index+2);
            }
        }
        return memo[index]=ways;
    }
    int numDecodings(string s) {
        str=s;
        n=s.size();
        memo.assign(n,-1);
        return dp(0);
    }
};
