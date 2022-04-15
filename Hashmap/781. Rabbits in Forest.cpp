int numRabbits(vector<int>& answers) {
        unordered_map<int,int>m;
        int ans=0;
        for(int i=0;i<answers.size();i++)
            answers[i]+=1;
        for(int i=0;i<answers.size();i++){
            m[answers[i]]+=1;
            if(m[answers[i]]==answers[i]){
                ans+=answers[i];
                m[answers[i]]=0;
            } 
        }
        for(auto x : m){
            if(x.second>0)
                ans+=x.first;
        }
        return ans;
    }
 
