bool isPossible(int mid, int arr[],int n, int p){
    int pratas=0;
    for(int l=0;l<n;l++){
        int r=arr[l];
        int time=mid;
        int i=1;
        time-=(i*r);
        i=2;
        while(time>0){
            pratas++;
            time=time-(i*r);
            i++;
        }
    }

    if(pratas>=p)
        return true;
    return false;
}
void binarySearch(int s, int e, int arr[], int n, int p, int& ans){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(isPossible(mid,arr,n,p)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
}
int main(){
    int arr[]={1,2,3,4};
    int p=6;
    int r=INT_MAX;
    int n=4;
    for(int i=0;i<n;i++){
        r=min(r,arr[i]);
    }
    int ans=-1;
    r = r*(p*(p+1)/2);
    binarySearch(0,r,arr,n,p,ans);
    cout<<ans;
}
