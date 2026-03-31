class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string curr="";
        for(int i=0;i<path.size();++i){
            if(path[i]=='/'){
                if(curr==".."){
                    if(!st.empty()){
                        st.pop();
                    }
                }
                else if(curr!="" and curr!="."){
                    st.push(curr);
                }
                curr="";
            }
            else{
                curr+=path[i];
            }
        }
        //processing last token
        if(curr==".."){
            if(!st.empty()){
                st.pop();
            }
        }
        else if(curr!="" and curr!="."){
            st.push(curr);
        }
        //building result
        vector<string> folders;
        while(!st.empty()){
            folders.push_back(st.top());
            st.pop();
        }
        reverse(folders.begin(),folders.end());
        string result="";
        for(auto &folder: folders){
            result+="/"+folder;
        }
        return result.empty() ? "/": result;
    }
};