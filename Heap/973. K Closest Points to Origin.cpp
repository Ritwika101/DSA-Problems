vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<points.size();i++){
            int x =  points[i][0];
            int y =  points[i][1];
            int dis = x*x;
            dis+=(y*y);
            pq.push({dis,{x,y}});
        }
        vector<vector<int>>ans;
        for(int i=1;i<=k;i++){
            if(pq.empty())
                break;
            auto a = pq.top();
            int x = a.second.first;
            int y = a.second.second;
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
    }
