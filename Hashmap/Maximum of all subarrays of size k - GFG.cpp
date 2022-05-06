vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        int s=0; //max
        for(int i=0;i<k;i++){
            if(s<=arr[i]){
                s=arr[i];
            }
            
        }
        vector<int>ans;
        ans.push_back(s);
        int rel=0;
        for(int acq=k;acq<n;acq++){
            int prev=arr[rel];
            rel++;
            if(prev==s){
                if(arr[acq]>=s)
                {
                    s=arr[acq];
                    ans.push_back(s);
                    
                }
                else{
                    int temp_max=0;
                    for(int i=rel;i<=acq;i++)
                        temp_max=max(temp_max,arr[i]);
                    s=temp_max;
                    ans.push_back(s);
                        
                }
            }
            else{
                if(arr[acq]>s){
                    s=arr[acq];
                    ans.push_back(s);
                }
                else
                    ans.push_back(s);
            }
        }
        return ans;
        
    }
