int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i=0;i<tokens.size();i++){
            string temp=tokens[i];
            if(temp=="+" || temp=="-" || temp=="*" || temp=="/"){
                int b = s.top();
                s.pop();  
                int a = s.top();
                s.pop();
                int ans=-1;
                if(temp=="+") 
                    ans=a+b;
                else if(temp=="-") 
                    ans=a-b;
                else if(temp=="*") 
                    ans=a*b;
                else if(temp=="/") 
                    ans=a/b;
                s.push(ans);
            }
            else{
                int num = stoi(temp);
                s.push(num);
            }
        }
        return s.top();
    }
