class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n=operations.size();
        for(int i=0;i<n;++i){
            if(isdigit(operations[i][0]) or (operations[i][0]=='-')){
                int num=stoi(operations[i]);
                st.push(num);
            }
            else if(operations[i]=="+"){
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.push(n1);
                st.push(n1+n2);
            }
            else if(operations[i]=="D"){
                st.push(2*st.top());
            }
            else{
                st.pop();
            }
        }
        int result=0;
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        return result;
    }
};