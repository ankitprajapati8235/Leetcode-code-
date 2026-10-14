class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        stack<string> st;

        string token;

        while(getline(ss, token, '/')) {
            if(token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if(st.size()>0) {
                    st.pop();
                }
            } else {
                st.push(token);
            }            
        }   
        string ans = "";
        while(st.size() > 0) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.size() == 0 ? "/" : ans;
    }    
};