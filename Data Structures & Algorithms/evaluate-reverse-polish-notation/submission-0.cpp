class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        for(int i=0;i<n;++i){
            if(tokens[i]=="+"){
                int n1=st.top(); st.pop();
                int n2=st.top(); st.pop();
                st.push(n1+n2);
            }
            else if(tokens[i]=="-"){
                int n1=st.top(); st.pop();
                int n2=st.top(); st.pop();
                st.push(n2-n1);
            }
            else if(tokens[i]=="*"){
                int n1=st.top(); st.pop();
                int n2=st.top(); st.pop();
                st.push(n2*n1);
            }
            else if(tokens[i]=="/"){
                int n1=st.top(); st.pop();
                int n2=st.top(); st.pop();
                st.push(n2/n1);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        while(!st.empty()){
            return st.top();
        }
    }
};
