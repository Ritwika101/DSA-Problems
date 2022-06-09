class Solution {
public:
   
    bool isValid(string t, int mid){
	unordered_map<string,int>m;
        int n=t.size();
        for(int i=0;i<=n-mid;i++){
            string temp=t.substr(i,mid);
            if(m.find(temp)!=m.end()) return true;
            m[temp]=1;
        }
        return false;
    }
    int longestRepeatingSubstring(string t) {
        int s=1,e=t.size();
        int ans=-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isValid(t,mid)){
                ans=max(ans,mid);
                s=mid+1;
            }
                
            else
                e=mid-1;
        }
        if(ans==-1) return 0;
        return ans;
    }
};
