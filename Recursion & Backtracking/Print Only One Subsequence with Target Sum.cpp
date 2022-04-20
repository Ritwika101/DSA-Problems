bool solve(int i, int n, int sum, int k, vector<int>nums, vector<int>&output){
   if(i==n && sum==k){
     for(int ind=0;ind<output.size();ind++)
       cout<<output[ind]<<"  ";
    cout<<endl;
	  return true;}
  else if(i>=n)
     return false;    
  output.push_back(nums[i]);
  sum+=nums[i];
  if(solve(i+1,n,sum,k,nums,output))
    return true;
  sum-=nums[i];
  output.pop_back();
  if(solve(i+1,n,sum,k,nums,output))
    return true;
  return false;
}
