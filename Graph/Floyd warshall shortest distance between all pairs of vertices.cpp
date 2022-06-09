void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int v = matrix.size();
	    vector<vector<int,int>>p=matrix;
	    
	    for(int i=0;i<matrix.size();i++){
	        for(int j=0;j<matrix[i].size();j++){
	            if(matrix[i][j]==-1)
	                matrix[i][j] = INT_MAX;
		    if(matrix[i][j]!=INT_MAX || matrix[i][j]!=-1)
			p[i][j] = j;
	        }
	    }
	    for(int k=0;k<v;k++){
	        for(int i=0;i<v;i++){
	            for(int j=0;j<v;j++){
	                if(matrix[i][k]==INT_MAX || matrix[k][j]==INT_MAX)
	                    continue;
			if(matrix[i][j] > matrix[i][k]+matrix[k][j]){
	                 matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
			p[i][j] = p[i][k];
			}
	            }
	        }
	    }
	    for(int i=0;i<matrix.size();i++){
	        for(int j=0;j<matrix[i].size();j++){
	            if(matrix[i][j]==INT_MAX)
	                matrix[i][j] = -1;
	        }
	    }
	   //path
	   int u=0,v=5; //say
	   vector<int>path;
	   path.push_back(u);
	   while(u!=v){
		u=p[u][v];
		path.push_back(u);
	   }
	}
