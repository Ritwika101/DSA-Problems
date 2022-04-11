
int value(int n, vector<int>&v){
        if(n==0)
            return v[key] = 0;
        if(n==1)
            return v[key] = 1;
        int key = n;
        if(v[key]!=-1)
            return v[key];
        else
            return v[n] = value(n-1,v)+value(n-2,v);  
        
    }
    int fib(int n) {
        vector<int>v(n+1,-1);
        return value(n,v);
        
    }
