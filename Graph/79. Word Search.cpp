class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    bool dfs(int x, int y, vector<vector<char>>& board,vector<vector<bool>>&vis, string word, int index){
        vis[x][y]=true;
        if(index==word.size()-1)
            return true;
        if(board[x][y]!=word[index])
            return false;
        index++;
        for(int i=0;i<4;i++){
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=0 && newy>=0 && newx<board.size() && newy<board[0].size() && !vis[newx][newy] && board[newx][newy] == word[index]){
                if(dfs(newx,newy,board,vis,word,index))
                    return true;
            }
        }
        vis[x][y]=false;
        return false;
            
    }
    bool exist(vector<vector<char>>& board, string word) {
        int u=0;
        int n=word.length();
        vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && !vis[i][j])
                {
                    if(dfs(i,j,board,vis,word,0))
                        return true;
                }
            }
        }
        return false;
    }
};
