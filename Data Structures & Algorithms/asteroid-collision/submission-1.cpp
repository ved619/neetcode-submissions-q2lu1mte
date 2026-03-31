class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        for(int i=0;i<n;++i){
            int curr=asteroids[i];
            bool destroyed= false;
            //collison only when top stack is +ve and curr is negative
            while(!st.empty() and st.top()> 0 and curr<0){
                if(abs(st.top())<abs(curr)){
                    st.pop();
                    continue;
                }
                else if(abs(st.top())==abs(curr)){
                    st.pop();
                }
                destroyed=true;
                break;
            }
            if(!destroyed){
                st.push(curr);
            }
        }
        vector<int> result(st.size());
        for(int i=st.size()-1;i>=0;--i){
            result[i]=st.top();
            st.pop();
        }
        return result;
    }
};