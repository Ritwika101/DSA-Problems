typedef long long int ll;
class Solution {
public:
    int numSquares(int n) {
        vector<int>v;
        int k = 1;
        while(true){
            int x = k*k;
            if(x>n)
                break;
            v.push_back(x);
            k++;
        }
        int m = v.size();
        int sum = n;
        int t[m+1][sum+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)
                    t[i][j]=INT_MAX;
                if(j==0)
                    t[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=sum;j++){
                if(v[i-1] <= j){
                    if(t[i][j-v[i-1]]!=INT_MAX)
                        t[i][j] = min(1+t[i][j-v[i-1]], t[i-1][j]);
                    else
                        t[i][j]=t[i-1][j];
                }
                    
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[m][sum];
    }
};
