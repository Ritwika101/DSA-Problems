bool findPair(int nums[], int n, int target){
    //code
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        int a = nums[i];
        int b1 = a - target;
        int b2 = a + target;
        if(m.find(b1)!=m.end() || m.find(b2)!=m.end())
            return true;
        m[a]=i;
    }
    return false;
}
