vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int s=INT_MIN; //max
        int n=arr.size();
        deque<int>d;
        for(int i=0;i<k;i++){
           while(!d.empty() && arr[d.back()]<arr[i])
                d.pop_back();     
            d.push_back(i);    
        }
        vector<int>ans;
        ans.push_back(arr[d.front()]);
        int rel=0;
        for(int acq=k;acq<n;acq++){
            while(!d.empty() && acq-d.front()>=k)
                d.pop_front();
             
            while(!d.empty() && arr[d.back()]<arr[acq])
                d.pop_back();
            
            d.push_back(acq);
            ans.push_back(arr[d.front()]);
        }
        return ans;
    }
