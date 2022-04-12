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
