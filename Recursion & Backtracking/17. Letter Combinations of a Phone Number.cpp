class Solution {
public:
    void solve(int i, vector<int>nums,vector<vector<char>>letter,string& output, vector<string>&ans){
        if(i==nums.size())
        {
            ans.push_back(output);
            return;
        }
        int digit=nums[i]-2;
        for(int k=0;k<letter[digit].size();k++){
            string old=output;
            output.push_back(letter[digit][k]);
            solve(i+1,nums,letter,output,ans);
            output=old;
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<int>nums;
        if(digits.size()==0)
            return {};
        for(int i=0;i<digits.size();i++){
            int num = digits[i]-'0';
            nums.push_back(num);
        }
        vector<string>ans;
        string output="";
        vector<vector<char>>letter(8);
        letter = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},
                            {'t','u','v'},{'w','x','y','z'}};
        solve(0,nums,letter,output,ans);
        return ans;
    }
};
