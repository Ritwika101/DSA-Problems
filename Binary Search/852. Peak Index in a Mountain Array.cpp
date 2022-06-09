int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size()-1;
        int s=0;
        int e=n;
        while(s<e){ 
            int mid=s+(e-s)/2;
            if(arr[mid]<arr[mid+1])
                s=mid+1;
           
            else if(arr[mid]>arr[mid+1])
                e=mid;
        }
        return s;
    }
