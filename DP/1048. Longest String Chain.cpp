class Solution {
public:
    static bool comp(string& s1, string& s2){
		return s1.size()<s2.size();
	}
   
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        int ans=1;
        vector<int>t(n,1);
        for(int i=1;i<n;i++){
            string s = words[i];
            int len = s.length();
            for(int j=0;j<i;j++){
                string temp=words[j];
                int templen = temp.length();
                if(len==templen+1){
                    int counter=1,k1=0,k2=0;
                    while(k1<len){
                        if(s[k1]==temp[k2])
                        {
                            k1++;
                            k2++;
                        }
                        
                        else
                            k1++;
                    }
                    if(k1==len && k2==templen){
                        t[i]=max(t[i],t[j]+1);
                    }
                }
            }
            ans=max(ans,t[i]);
        }
        return ans;
    }
};
