void solve(int i, int n, int sum, int k, vector<int>nums, vector<int>&output){
    if(i==n && sum==k){
	    for(int ind=0;ind<output.size();ind++)
        cout<<output[ind]<<"  ";
      cout<<endl;
	    return;
    }
    else if(i>=n)
        return;
    
    output.push_back(nums[i]);
    sum+=nums[i];
    solve(i+1,n,sum,k,nums,output);
    sum-=nums[i];
    output.pop_back();
    solve(i+1,n,sum,k,nums,output);
    return;
}
