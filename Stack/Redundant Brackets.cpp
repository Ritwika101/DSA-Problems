bool findRedundantBrackets(string &s)
{
    // Write your code here.
	int n=s.size();
	stack<char>st;
	for(int i=0;i<n;i++){
		if(s[i]=='(' || s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')
			st.push(s[i]);
		else if(s[i]==')'){
			if(st.top()=='*' || st.top()=='/' || st.top()=='+' || st.top()=='-'){
				while(st.top()!='(')
					st.pop();
				st.pop();
			}
			else
				return true;
		}
	}
	return false;
}
