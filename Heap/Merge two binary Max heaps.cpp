void heapify(vector<int>&c, int i, int n){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n && c[largest]<c[left])
            largest=left;
        if(right<n && c[largest]<c[right])
            largest=right;
        if(largest!=i)
        {
            swap(c[i],c[largest]);
            heapify(c,largest,n);
        }
        return;
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>c(n+m,0);
        int k=0;
        int i=0, j=0;
        for(int i=0;i<n;i++)
            c[i]=a[i];
        for(int i=0;i<m;i++)
            c[i+n]=b[i];
        int total = n+m;
        for(int i=total/2-1;i>=0;i--)
            heapify(c,i,total);
        return c;
    }
