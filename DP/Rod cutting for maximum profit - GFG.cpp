
class Solution{
  public:
  int t[1001][1001];
  int solve(int n, int l, int price[]){
      if(n==0)
        return t[n][l]=0;
      if(l==0)
        return t[n][l]=0;
     if(t[n][l]!=-1)
        return t[n][l];
     if(n<=l)
        return t[n][l]=max(price[n-1]+solve(n,l-n,price), solve(n-1,l,price));
     else
        return t[n][l]=solve(n-1,l,price);
  }
    int cutRod(int price[], int n) {
        //code here
        memset(t,-1,sizeof(t));
        int m=sizeof(price)/sizeof(price[0]);
       
        return solve(m,n,price);
    }
};
