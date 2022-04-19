bool isValidSudoku(vector<vector<char>>& board) {
        map<char, vector<pair<int,int>>>m;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                
                if(m.find(board[i][j])==m.end())
                    m[board[i][j]].push_back({i,j});
                else{
                    for(int k=0;k<m[board[i][j]].size();k++){
                        int x = m[board[i][j]][k].first;
                        int y = m[board[i][j]][k].second;
                        if(x==i || y==j)
                            return false;
                        else if(i/3==x/3 && j/3==y/3)
                            return false;
                        
                    }
                    m[board[i][j]].push_back({i,j});
                    
                }
            }
        }
        return true;
    }
