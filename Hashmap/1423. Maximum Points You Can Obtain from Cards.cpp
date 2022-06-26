
int maxScore(vector<int>& cards, int k) {
        int n=cards.size();
        int sum = 0;
        for(int i=0;i<n;i++)
            sum+=cards[i];
        int totalsum = sum;
        if(k>=n) return totalsum;
        int minsum = INT_MAX;
        sum = 0;
        int rel=0;
        int j = n-k;
        for(int i=0;i<j;i++)
            sum+=cards[i];
        minsum = sum;
        for(int acq=j;acq<n;acq++){
            sum-=cards[rel];
            rel++;
            sum+=cards[acq];
            minsum = min(minsum, sum);
        }
        return totalsum - minsum;
    }
