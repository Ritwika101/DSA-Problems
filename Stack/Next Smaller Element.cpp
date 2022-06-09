vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
	stack<int>s;
        s.push(-1);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            if(s.top()<nums[i]){
                ans[i]=s.top();
            }
            else{
                while(s.top()!=-1 && nums[i]<=s.top())
                    s.pop();
                ans[i]=s.top();
            }
            s.push(nums[i]);
        }
        return ans;
}
