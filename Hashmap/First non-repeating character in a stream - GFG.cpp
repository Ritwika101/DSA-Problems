string FirstNonRepeating(string a){
 // Code here
	string ans="";
       queue<char>q;
	if(a.size()==0)
		    return "";
	unordered_map<char,int>m;
	for(int i=0;i<a.size();i++){
		  m[a[i]]++;
		  q.push(a[i]);
		  while(!q.empty()){
			  if(m[q.front()]>1)
		         q.pop();
		    else
		    {
		         ans.push_back(q.front());
		         break;
		    }
		  }
		if(q.empty())
		       ans.push_back('#');
		     
	}
	return ans;
		    
}
