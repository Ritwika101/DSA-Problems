int findMinimumCost(string str) {
  // Write your code here
	if(str.length()&1==1)
		return -1;
	stack<char>s;
	for(int i=0;i<str.size();i++){
		if(str[i]=='{')
			s.push(str[i]);
		else if(str[i]=='}')
		{
			if(s.empty() || s.top()!='{')
				s.push(str[i]);
			
			else if(s.top()=='{')
				s.pop();
		}
	}
	int a=0, b=0;
	while(!s.empty()){
		if(s.top()=='{')
			a++;
	    else if(s.top()=='}')
			b++;
		s.pop();
	}
	if(a==0)
		return b/2;
	else if(b==0)
		return a/2;
	else
		return ((a+1)/2 + (b+1)/2);
	
}
