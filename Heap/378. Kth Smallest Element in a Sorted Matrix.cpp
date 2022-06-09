int find(vector<int>row, int target){
        int ans=-1;
        int s=0, e=row.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(row[mid]<=target){
                 s=mid+1;
            }
            else if(row[mid]>target){
                e=mid-1;
            }
        }
        return s;  
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int s=matrix[0][0];
        int e=matrix[n-1][m-1];
        while(s<=e){
            int mid = s+(e-s)/2;
            int countLeft=0;
            for(int i=0;i<n;i++){
                
                int x =find(matrix[i],mid);
                if(x!=-1)
                    countLeft+=x;
            }
            if(countLeft<k)
                s=mid+1;
            else 
                e=mid-1;
            
        }
        return s;
    }
