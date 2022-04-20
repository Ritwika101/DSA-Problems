void solve(int i, int n, vector<int>nums, vector<int>&output){
	if(i>=n){
		for(int k=0;k<output.size();k++)
      cout<<output[k];
    cout<<endl;
		return;
	}
	output.push_back(nums[i]);
  solve(i+1,n,nums,output);
  output.pop_back();
	solve(i+1,n,nums,output);
	return;
}
