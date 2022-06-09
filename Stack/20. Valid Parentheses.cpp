bool isValid(string s) {
        stack<char>st;
        if(s.size()==0)
            return true;
        if(s[0]==')' || s[0]=='}' || s[0]==']')
            return false;
        //int i=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else if(s[i]==')'){
                if(st.empty())
                    return false;
                else if(st.top()!='(')
                    return false;
                else
                    st.pop();
            }
            else if(s[i]=='}'){
                if(st.empty())
                    return false;
                else if(st.top()!='{')
                    return false;
                else
                    st.pop();
            }else if(s[i]==']'){
                if(st.empty())
                    return false;
                else if(st.top()!='[')
                    return false;
                else
                    st.pop();
            }
        }
        if(st.size()==0)
            return true;
        return false;
    }
