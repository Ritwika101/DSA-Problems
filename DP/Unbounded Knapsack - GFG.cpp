class Solution{
public:
int t[1001][1001];
int solve(int n, int w, int val[], int wt[]){
    if(w==0)
        return t[n][w]=0;
    if(n==0)
        return t[n][w]=0;
    if(t[n][w]!=-1)
        return t[n][w];
    if(wt[n-1]<=w)
        return t[n][w]=max((val[n-1]+solve(n,w-wt[n-1],val,wt)), solve(n-1,w,val,wt));
    else
        return t[n][w]=solve(n-1,w,val,wt);
}
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(t,-1,sizeof(t));
        return solve(N, W, val, wt);
    }
};
