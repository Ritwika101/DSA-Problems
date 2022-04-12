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
    set<string>store;
    unordered_map<char,ll>m;
    int rel = 0;
    for(int acq=0;acq<n;acq++){
        while(rel<acq && m[s[acq]]>0){
            m[s[rel]]-=1;
            rel+=1;
        }
        m[s[acq]]+=1;
        for(int j=rel;j<=acq;j++)
            store.insert(s.substr(j, acq-j+1));
        
    }
    cout<<store.size();
}
