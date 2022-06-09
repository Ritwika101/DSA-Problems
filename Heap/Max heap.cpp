int parent(int i){
    return (i-1)/2;
}
void heapify(int i, int n, vector<int>&nums){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n && nums[left]>nums[largest])
        largest=left;
    if(right<n && nums[right]>nums[largest])
        largest=right;
    if(largest!=i){
        int temp=nums[i];
        nums[i]=nums[largest];
        nums[largest]=temp;
        heapify(largest,n,nums);
        return;
    }
    return;
}
void buildHeap(vector<int>&nums, int n){
    int m = n/2 - 1;
    for(int i=m;i>=0;i--)
        heapify(i,n,nums);
}
void heapSort(vector<int>&nums, int n){
    buildHeap(nums,n);
    for(int i=n-1;i>0;i--){
        int max=nums[0];
        int temp=nums[i];
        nums[i]=max;
        nums[0]=temp;
        heapify(0,i,nums);
    }
}
int remove(vector<int>&nums, int n){
    int max=nums[0];
    nums[0]=nums[n-1];
    nums.erase(nums.end()-1);
    n--;
    //cout<<n<<endl;
    heapify(0,n,nums);
    return max;
}
void heapifyInsertion(int i, int n, vector<int>&nums){
    int p=parent(i);
    int key=nums[i];
    while(p>=0 && i>0 && nums[p]<key){
        nums[i]=nums[p];
        i=p;
        p=parent(p);
    }
    nums[i]=key;
}
void insert(vector<int>&nums, int n, int key){
    nums.push_back(key);
    heapifyInsertion(nums.size()-1,nums.size(),nums);
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    heapSort(nums,n);
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
}
