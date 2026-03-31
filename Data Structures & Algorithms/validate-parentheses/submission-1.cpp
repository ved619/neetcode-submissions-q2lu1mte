class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> st;
        for(int i=0;i<n;++i){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if(s[i]==']' and st.top()=='['){
                    st.pop();
                }
                else if(s[i]==')' and st.top()=='('){
                    st.pop();
                }
                else if(s[i]=='}' and st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty())return true;
        return false;
    }
};
