int solve(int i, int n, int sum, int k, vector<int>nums){ 
    if(i==n){
        if(sum==0)
	   return 1;
        return 0;
    }	
    int pick = solve(i+1,n,sum-nums[i],k,nums);
    int dontPick = solve(i+1,n,sum,k,nums);
    return pick+dontPick;
}

int main()
{
    vector<int>s;
    int n=4,k=3,sum=0,i=0;
    vector<int>output;
    s.push_back(3);
    s.push_back(1);
    s.push_back(1);
    s.push_back(2);
    cout<<solve(i,n,k,k,s);
}
