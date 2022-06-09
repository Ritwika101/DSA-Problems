
void insertAtPos(stack<int>&s, int x){
	if(s.empty() || s.top()<x)
	{
		s.push(x);
		return;
	}
	int num=s.top();
	s.pop();
	insertAtPos(s,x);
	s.push(num);
	return;
}
void sortStack(stack<int> &s)
{
	// Write your code here
	if(s.empty())
		return;
	int num=s.top();
	s.pop();
	sortStack(s);
	insertAtPos(s,num);
	return;
}
