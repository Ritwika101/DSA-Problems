class MinStack {
public:
    stack<int>s;
    stack<int>mins;
    /** initialize your data structure here. */
    MinStack() {   
    }
    
    void push(int x) {
       s.push(x);
       if(mins.empty()){
           mins.push(s.top());
       }
        else{
            int temp = min(mins.top(),s.top());
            mins.push(temp);
        }
    }
    
    void pop() {
      s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
       return mins.top();
    }
};
