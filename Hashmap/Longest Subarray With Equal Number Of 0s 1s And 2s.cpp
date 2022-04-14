int main(){
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    int ans=0,z0=0,z1=0;
    int z2=0;
    map<pair<int,int>>m;
    m[{0,0}]=-1;
    for(int i=0;i<n;i++){
        if(nums[i]==0)
            z0++;
        else if(nums[i]==1)
            z1++;
        else
            z2++;
        pair<int,int>p={z1-z0,z2-z1};
        if(m.find(p)==m.end())
            m[p]=i;
        else{
            ans=max(ans,i-m[p]);
        }
            
    }
    cout<<ans;
}
