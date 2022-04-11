bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>m; 
        for(int i = 0; i < arr.size(); i++){
            int x = (k + (arr[i]%k)) % k; 
            m[x]++;
        }
            
        for(int i=0;i<=k/2;i++){
            if(i==0){
                if(m[i] % 2 != 0) return false; 
            }
            else{
                int b = k-i;
                if(m[b] != m[i]) return false; 
            }
         }
         return true;
    }
