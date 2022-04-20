void solve(int n, string& output, vector<string>&res, int open, int close){
        if(output.size()==2*n){
            res.push_back(output);
            return;}
        if(open<n){
            output.push_back('(');
            solve(n,output,res,open+1,close);
            output.pop_back();
        }
        if(close<open){
            output.push_back(')');
            solve(n,output,res,open,close+1);
            output.pop_back();
        }          
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string output="";
        solve(n, output, res, 0,0);
        return res;
    }
