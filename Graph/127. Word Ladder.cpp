class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        vector<bool>vis(n);
        /*if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
            return 0;*/
        if(beginWord==endWord)
            return 0;
         queue<pair<int,int>>q;
         q.push({-1,1});
         while(!q.empty()){
             auto p=q.front();
             int u=p.first;
             int dis=p.second;
             
             q.pop();
             if(u!=-1)
             {  
                 vis[u]=true;
                 //cout<<wordList[u]<<endl;
                 if(wordList[u]==endWord)
                    return dis;
             }
             for(int k=0;k<n;k++){
                 if(!vis[k]){
                     string a="";
                     if(u==-1)
                         a=beginWord;
                     else
                        a=wordList[u];
                     string b=wordList[k];
                     int count=0;
                     for(int l=0;l<a.size();l++){
                         if(count>1)
                             break;
                          if(a[l]!=b[l])
                              count++; 
                     }
                     if(count==1){
                         q.push({k,dis+1});
                         vis[k]=true;
                     }    
                 }
             }
         }
        return 0;
    }
};
