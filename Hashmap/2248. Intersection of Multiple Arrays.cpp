class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int>m;
        vector<int>res;
        if(nums.size()==0)
            return res;
        if(nums.size()==1){
            for(int i=0;i<nums[0].size();i++)
                res.push_back(nums[0][i]);
            sort(res.begin(),res.end());
            return res;
        }
        for(int j=0;j<nums[0].size();j++){
            m[nums[0][j]]=1;
        }      
        for(int i=0;i<nums.size();i++){
            for(auto x : m){
                bool flag=false;
                for(int j=0;j<nums[i].size();j++){
                    if(nums[i][j]==x.first && x.second==1){  
                        flag=true;
                        break;
                    }
                }
                
                if(flag){
                    m[x.first]=1;
                }
                else{         
                    m[x.first]=0;
                }
            }
           
        }
          
        for(auto x : m){
            if(x.second!=0)
                res.push_back(x.first);
        }
        sort(res.begin(),res.end());
        return res;
    }
};
