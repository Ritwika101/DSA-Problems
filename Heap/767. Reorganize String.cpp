#define pi pair<int,char>
    string reorganizeString(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
        priority_queue<pi>pq;
        string ans="";
        for(auto x : m)
            pq.push({x.second,x.first});
        while(pq.size()>1){
            auto a=pq.top();
            pq.pop();
            auto b=pq.top();
            pq.pop();
            char c1 = a.second, c2 = b.second;
            ans.push_back(c1);
            ans.push_back(c2);
            a.first-=1;
            b.first-=1;
            if(a.first>0)
                pq.push(a);
            if(b.first>0)
                pq.push(b);
        }
        if(!pq.empty() && pq.top().first>1)
            return "";
        else if(ans[ans.size()-1]!=pq.top().second)
            ans.push_back(pq.top().second);
        return ans;
    }
