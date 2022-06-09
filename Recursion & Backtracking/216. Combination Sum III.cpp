void solve(int i, int k, int target, int num, vector<int>&output, vector<vector<int>>&ans){
       if(i==k && target==0){
           ans.push_back(output);
           return;
       }
        if(i==k) return;
        if(num>9) return;
        output.push_back(num);
        solve(i+1,k,target-num,num+1,output,ans);
        output.pop_back();
        solve(i,k,target,num+1,output,ans);
            
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> output;
        int sum=0;
        vector<vector<int>>ans;
        int target=n;
        int num=1;
        solve(0,k,target,num,output,ans);
        return ans;
    }
