class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0;i<s.size();i++){
            switch(s[i]){
                case ')':
                    if(st.empty()||st.top()!='(')
                        return false;
                    else
                        st.pop();
                    break;
                case ']':
                    if(st.empty()||st.top()!='[')
                        return false;
                    else
                        st.pop();
                    break;
                case '}':
                    if(st.empty()||st.top()!='{')
                        return false;
                    else
                        st.pop();
                    break;
                default:
                    st.push(s[i]);
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
