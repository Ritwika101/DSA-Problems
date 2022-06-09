
int pivot(vector<int>& arr) {
        int n=arr.size()-1;
        int s=0;
        int e=n-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(arr[mid]>=arr[0])
                s=mid+1;
           
            else 
                e=mid;
        }
        return s;
    }
