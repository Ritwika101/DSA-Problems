
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
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here 
        int n = (r*c+1)/2; //3x3 -> 4
        int minNum=INT_MAX, maxNum=INT_MIN;
        for(int i=0;i<r;i++){
            minNum = min(minNum,matrix[i][0]);
            maxNum = max(maxNum, matrix[i][c-1]);
        }
        int s=minNum, e=maxNum;
        while(s<=e){
            int mid = s+(e-s)/2; //middle element
            int countLeft=0;
            for(int i=0;i<r;i++){
                
                int x =find(matrix[i],mid);
                if(x!=-1)
                    countLeft+=x;
            }
            if(countLeft<n)
                s=mid+1;
            else 
                e=mid-1;
            
        }
        return s;
    }
