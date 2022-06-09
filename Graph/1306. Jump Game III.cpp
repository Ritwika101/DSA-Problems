bool canReach(vector<int>& arr, int start) {
        vector<int>d;
        int n=arr.size();
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
                d.push_back(i);
        }
        vector<pair<int,int>>p(n);
        for(int i=0;i<arr.size();i++){
            int x = i-arr[i];
            int y = i+arr[i];
            if(x>=0 && x<n)
                p[i].first = x;
            else
                p[i].first = -1;
            if(y>=0 && y<n)
                p[i].second = y;
            else
                p[i].second = -1;
        }
        queue<int>q;
        q.push(start);
        map<int, bool>vis;
        vis[start]=true;
        
        while(!q.empty()){
             int u = q.front();
             q.pop();
            for(int i=0;i<d.size();i++){
                if(d[i]==u)
                    return true;
            }
           
            if(p[u].first!=-1 && !vis[p[u].first]){
                q.push(p[u].first);
                vis[p[u].first]=true;}
            if(p[u].second!=-1&& !vis[p[u].second]){
                q.push(p[u].second);
                vis[p[u].second]=true;}
            
        }
        return false;
    }
