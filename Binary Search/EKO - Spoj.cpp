//Available on spoj.com
bool isPossible(int mid, int arr[],int n, int target){
    int sum=0;
    for(int i=0;i<n;i++){
        int diff=0;
        if(arr[i]>mid)
            diff=arr[i]-mid;
        sum+=diff;
    }
    if(sum>=target)
        return true;
    return false;
}
void binarySearch(int s, int e, int arr[], int n, int target, int& ans){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(isPossible(mid,arr,n,target)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
}
int main(){
    int arr[]={18,8,15,6};
    int target=30;
    int maxh=0;
    int n=4;
    for(int i=0;i<n;i++){
        maxh=max(maxh,arr[i]);
    }
    int ans=-1;
    binarySearch(0,maxh,arr,n,target,ans);
    cout<<ans;
}
