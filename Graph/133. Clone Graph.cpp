
Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*>m;
        Node* start = new Node(node->val,{});
        m[node]=start;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* u = q.front();
            q.pop();
            for(Node* v : u->neighbors){
                if(m.find(v)==m.end()){
                    Node* child = new Node(v->val,{});
                    m[v]=child;
                    q.push(v);
                }
                m[u]->neighbors.push_back(m[v]);
            }
        }
        return start;
    }
