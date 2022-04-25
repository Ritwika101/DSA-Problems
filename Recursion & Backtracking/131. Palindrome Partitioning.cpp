class Solution {
public:
    bool palindrome(string s, int i, int j){
        bool flag = true;
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<string>>&v, vector<string>&curr, string s, int start){
        if(start>=s.length())
            v.push_back(curr);
        for(int j = start;j<s.length();j++){
            
            if(palindrome(s,start,j)){  
                curr.push_back(s.substr(start,j-start+1));
                
                solve(v,curr,s,j+1);
                curr.pop_back();
            }        
        }
       
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>v;
        int n = s.length();
        vector<string>curr;
        solve(v,curr,s,0);
        return v;
    }
};

