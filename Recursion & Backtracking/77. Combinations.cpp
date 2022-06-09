void solve(int i, int k, int num, int n, vector<int>&output, vector<vector<int>>&ans){
        if(i==k){
            ans.push_back(output);
            return;
        }
        if(num>n)
            return;
        output.push_back(num);
        solve(i+1,k,num+1,n,output,ans);
        output.pop_back();
        solve(i,k,num+1,n,output,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>output;
        vector<vector<int>>ans;
        int i=0,num=1;
        solve(i,k,num,n,output,ans);
        return ans;
    }
