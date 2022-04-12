
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits.h>
#include<queue>
#include<set>
#include<unordered_map>
#include<bits/stdc++.h>
#define ll long long int

int main(){
    string s;
    cin>>s;
    ll n=s.length();
    int k;
    cin>>k;
    unordered_map<char,ll>m;
    int rel = 0;
    ll distinct=0;
    ll ans=0;
    for(int acq=0;acq<n;acq++){
        //cout<<rel<<"*"<<distinct<<endl;
        if(m[s[acq]]==0)
            distinct+=1;
        m[s[acq]]+=1;
        while(rel<=acq && distinct>k){
            m[s[rel]]-=1;
            if(m[s[rel]]==0)
                distinct-=1;
            rel+=1;
        }
        ans+=(acq-rel+1);
        //for(int j=rel;j<=acq;j++)
        //    cout<<s.substr(j,acq-j+1)<<endl;
        
    }
    cout<<ans;
}
