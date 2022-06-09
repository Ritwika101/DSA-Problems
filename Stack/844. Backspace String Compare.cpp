
bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;
        int n=s.length(), m=t.length();
        for(int i=0;i<n;i++){
            if(s1.empty() && s[i]=='#')
                continue;
            else if(!s1.empty() && s[i]=='#')
                s1.pop();
            else if(s[i]!='#')
                s1.push(s[i]);
        }
        for(int i=0;i<m;i++){
            if(s2.empty() && t[i]=='#')
                continue;
            else if(!s2.empty() && t[i]=='#')
                s2.pop();
            else if(t[i]!='#')
                s2.push(t[i]);
        }
        string ans1="", ans2="";
        while(!s1.empty())
        {
            ans1+=to_string(s1.top());
            s1.pop();
        }
        while(!s2.empty())
        {
            ans2+=to_string(s2.top());
            s2.pop();
        }
        return (ans1==ans2);
        
    }
