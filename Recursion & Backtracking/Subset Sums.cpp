
//Given a list arr of N integers, print sums of all subsets in it.

void solve(int i, int n, int sum, vector<int> &nums,vector<int> &output){
        if(i==n){
            output.push_back(sum);
            return;}
        sum+=nums[i];
        solve(i+1,n,sum,nums,output);
        sum-=nums[i];
        solve(i+1,n,sum,nums,output);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int>output;
        solve(0,N,0,arr,output);
        return output;
    }
