int doUnion(int a[], int n, int b[], int m)  {
        //code here
        sort(a,a+n);
        sort(b,b+m);
        int i=0,j=0;
        vector<int>ans;
        while(i<n && j<m){
            if(i>0 && a[i]==a[i-1]){
                i++;
                continue;
            }
            if(j>0 && b[j]==b[j-1]){
                j++;
                continue;
            }
            if(a[i]<b[j]){
                ans.push_back(a[i]);
                i++;
            }
            else if(a[i]>b[j]){
                ans.push_back(b[j]);
                j++;
            }
            else{
                ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        while(i<n){
           if(i>0 && a[i]==a[i-1]){
                i++;
                continue;
            }
           ans.push_back(a[i]);
           i++; 
        }
        while(j<m){
            if(j>0 && b[j]==b[j-1]){
                j++;
                continue;
            }
           ans.push_back(b[j]);
           j++; 
        }
        return ans.size();
    }
