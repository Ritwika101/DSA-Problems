string frequencySort(string s) {
        priority_queue<pair<int,ll>,vector<pair<int,ll>>>pq;
        unordered_map<char,ll>m;
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        for(auto x: m){
            pq.push({x.second,x.first});
        }
        string ans="";
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            ll freq=p.first;
            char u = p.second;
            for(ll i=1;i<=freq;i++)
                ans.push_back(u);
        }
        return ans;
    }
