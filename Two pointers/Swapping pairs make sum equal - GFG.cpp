int findSwapValues(int a[], int n, int b[], int m)
	{
        // Your code goes here
        int suma=0, sumb=0;
        for(int i=0;i<n;i++)
            suma+=a[i];
        for(int j=0;j<m;j++)
            sumb+=b[j];
        if((suma-sumb)%2!=0)
            return -1;
        ll target = (suma-sumb)/2;
        sort(a,a+n);
        sort(b, b+m);
        int x=0,y=0;
        while(x<n && y<m){
            ll diff = a[x]-b[y];
            if(diff==target){
                return 1;
            }
                
            else if(diff<target){
                x++;
            }
            else
                y++;
                
        }
        return -1 ;
	}
