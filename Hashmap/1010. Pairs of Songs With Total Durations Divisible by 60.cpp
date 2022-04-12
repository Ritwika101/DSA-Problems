
int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> m;
        int res = 0;
        for (int x : time) 
        { 
            int r1 = x%60;
            int r2 = 60-r1;
            if(r1==0)
                res+=m[0];
            else if(m[r2]!=0)
                res+=m[r2]; 
            m[r1]++;             
        }   
        return res;
    }
