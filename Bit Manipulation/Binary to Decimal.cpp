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
    int n=110;
    int ans=0, i=0;
    while(n!=0){
        int bit=n%10;
        ans=ans+(bit*pow(2,i));
        i+=1;
        n=n/10;
    }
    cout<<ans;
    return 0;
}
