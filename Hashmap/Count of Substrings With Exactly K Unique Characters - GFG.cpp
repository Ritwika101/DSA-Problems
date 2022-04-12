#define ll long long int
class Solution
{
  public:
  long long int countAtmostK(string s, int k) {
    if(s.size()==0 || k==0) return 0;
    long long int c=0,ans=0,rel=0,acq=0,n=s.size();
    int m[26]={0};
    while(acq<n){ 
        m[s[acq]-'a']++;
        if(m[s[acq]-'a']==1)
            c++;
        while(rel<acq && c>k){
            m[s[rel]-'a']--;
            if(m[s[rel]-'a']==0)
                c--;
            rel++;
        }
        ans+=(acq-rel+1);
        acq++;
    }
    return ans;
}
  
    long long int substrCount(string s, int k) {
    	return countAtmostK(s,k)-countAtmostK(s,k-1);
    }
