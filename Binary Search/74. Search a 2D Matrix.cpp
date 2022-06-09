bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int s=0,e=rows-1;
        
        while(s<=e){
            int m = s+(e-s)/2;
            if(target < matrix[m][0])
                e=m-1;
            else if(target>matrix[m][cols-1])
                s=m+1;
            else
                break;
        }
        if(s>e)
            return false;
        int row = s+(e-s)/2;
        s=0,e=cols-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(target==matrix[row][m])
                return true;
            else if(target<matrix[row][m])
                e=m-1;
            else
                s=m+1;
        }
        return false;
    }
