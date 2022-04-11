class Solution {
public:
    
    bool isPalindrome(string &s, int start, int end) {
        while(end >= start) {
            if (s[start] != s[end]) {
                return false;
            }   
            start++;
            end--;
        }
        return true;
    }
    int solve(string &s, int start, int end, vector<vector<int>>&t) {
       
        if (t[start][end] != -1)
             return t[start][end];
        if(start>=end)
            return t[start][end] = 0;
        if (isPalindrome(s, start, end)) 
            return t[start][end] = 0;  
        int ans = INT_MAX;
        for (int i = start; i < end; i++) {
            if (isPalindrome(s, start, i)) {
                int temp = solve(s, i+1, end, t);
                if(temp!=INT_MAX)
                    ans = min(ans, 1 + temp);
            }
        }
        
        return t[start][end] = ans;
    }
    int minCut(string s) {
         
        int n = s.length();
        vector<vector<int>>t(n+1,vector<int>(n+1,-1));  
        int ans = solve(s, 0, s.length() - 1, t);
        return ans;
    }    
    
};
