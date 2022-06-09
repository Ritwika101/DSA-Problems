
class Solution {
public:
    vector<int> nextSmaller(vector<int>heights, int m){
        stack<int>s;
        s.push(-1);
        vector<int>ans(m);
        for(int i=m-1;i>=0;i--){
            while(s.top()!=-1 && heights[s.top()]>=heights[i])
                s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
        
    }
    vector<int> prevSmaller(vector<int>heights, int m){
        stack<int>s;
        s.push(-1);
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            while(s.top()!=-1 && heights[s.top()]>=heights[i])
                s.pop();
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
        
    }
    int findArea(vector<int>heights, int m){
        vector<int>prev(m);
        vector<int>next(m);
        prev=prevSmaller(heights,m);
        next=nextSmaller(heights,m);
        int area=INT_MIN;
        for(int i=0;i<m;i++){
            if(next[i]==-1)
                next[i]=m;
            int temp=next[i]-prev[i]-1;
            temp=temp*heights[i];
            area=max(area,temp);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix[0].size();
        int n=matrix.size();
        vector<vector<int>>grid(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')
                    grid[i][j]=0;
                else
                    grid[i][j]=1;
            }
        }
        
        vector<int>ans(n);
        int area = findArea(grid[0],m);
        for(int i=1;i<n;i++){  
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0)
                    grid[i][j]+=grid[i-1][j];
            }
            vector<int>row(m);
            row = grid[i];
            int temp_area=findArea(row,m);
            area=max(area,temp_area);
        }
        return area;
    }
};
