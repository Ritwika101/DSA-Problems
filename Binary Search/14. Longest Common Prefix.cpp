
bool isPrefix(int len, vector<string>& strs ){
        string temp = strs[0].substr(0,len);
        for(int i=1;i<strs.size();i++){
            if(temp!=strs[i].substr(0,len)) return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int len = INT_MAX;
        if(strs.size()==0) return "";
        else if(strs.size()==1) return strs[0];
        for(int i=0;i<strs.size();i++){
            if(len>strs[i].size())
                len=strs[i].size();
        }
        string ans="";
        int res = -1;
        int low = 1;
        int high = len;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPrefix(mid,strs)){
                res=mid;
                low=mid+1;
            }
            else high=mid-1;
                
        }
        if(res==-1) return "";
        ans = strs[0].substr(0,res);
        return ans;
    }
