#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>
#include<limits.h>
#include<map>
#include<stack>
#include<unordered_map>
#include<bits/stdc++.h>
#define ll long long 
int main(){
    int n=6;
    int ans=0, i=0;
    while(n!=0){
        int bit = n&1;
        ans=ans+(bit*pow(10,i));
        i+=1;
        n=n>>1;

    }
    cout<<ans;
    return 0;
}
