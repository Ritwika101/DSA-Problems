//Concept of subarray minimums is used
int uniqueLetterString(string s) {
        unordered_map<char,vector<int>>m;
        for(int i=0;i<s.size();i++){
            m[s[i]].push_back(i);
        }
        int sum = 0;
        int n=s.size();
        for(auto  p : m){
            char c = p.first;
            vector<int>indexes = p.second;
            int left = -1, right = -1;
            for(int i=0;i<indexes.size();i++){
                if(i==0)
                    left = -1;
                else left = indexes[i-1];
                if(i==indexes.size()-1)
                    right=-1;
                else
                    right=indexes[i+1];
                int countLeft=0, countRight=0;
                if(left!=-1)
                    countLeft = indexes[i] - left;
                else 
                    countLeft = indexes[i]+1;
                if(right!=-1)
                    countRight = right - indexes[i];
                else
                    countRight = n-indexes[i];
                sum+=(countRight*countLeft);
            }
            
        }
        return sum;
    }
