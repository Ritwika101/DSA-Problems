int longestValidParentheses(string s) {
        int open=0,close=0,maxlen=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open++;
            else close++;
            if(open==close)
                maxlen=max(maxlen,2*close);
            else if(close>open){
                open=0;
                close=0;
            }
        }
        open=0,close=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;
            if(open==close)
                maxlen=max(maxlen,2*open);
            else if(open>close){
                open=0,close=0;
            }
        }
        return maxlen;
    }
