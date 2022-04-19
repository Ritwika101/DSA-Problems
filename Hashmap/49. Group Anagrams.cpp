vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,int>m;
        vector<vector<string>>ans;
        int k=0;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());     
            if(m.find(s)==m.end()){
                m[s]=k;
                vector<string>temp;
                temp.push_back(strs[i]);
                ans.push_back(temp); 
                k++;
            }
            else{
                int index = m[s];
                ans[index].push_back(strs[i]);
            }
        }
        return ans;
    }



