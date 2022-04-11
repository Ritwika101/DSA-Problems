int main(){
    string s;
    cin>>s;
    ll ans = 0;
    ll n=s.length();
    unordered_map<char,ll>m;
    int rel = 0;
    for(int acq=0;acq<n;acq++){
        while(rel<acq && m[s[acq]]>0){
            m[s[rel]]-=1;
            rel+=1;
        }
        m[s[acq]]+=1;
        ll temp_ans = acq-rel+1;
        ans+=temp_ans;
    }
    cout<<ans;
}
