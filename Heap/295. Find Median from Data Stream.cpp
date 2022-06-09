class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double>maxheap;
    priority_queue<double,vector<double>,greater<double>>minheap;
    int n;
    double median=-1.0;
    MedianFinder() {
    }
    int signum(int a, int b){
        if(a==b) return 0;
        else if(a>b) return 1;
        else return -1;
    }
    void callMedian(int num, priority_queue<double>&maxheap,priority_queue<double,vector<double>,greater<double>>&minheap, double& median){
        switch(signum(maxheap.size(),minheap.size()))
        {
            case 0:if(num>median){
                    minheap.push(num);
                    median = minheap.top();
                }
                else{
                    maxheap.push(num);
                    median=maxheap.top();
                }
                break;
            case 1:if(num>median){
                    minheap.push(num);
                    median=(maxheap.top() + minheap.top())/2;
                    
                }
                else{
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(num);
                    median=(maxheap.top() + minheap.top())/2;
                }
                break;
            case -1: if(num>median){
                    maxheap.push(minheap.top());
                    minheap.pop();
                    minheap.push(num);
                    median=(maxheap.top() + minheap.top())/2;
                }
                else{
                    maxheap.push(num);
                     median=(maxheap.top() + minheap.top())/2;
                }
                break;
        }
    }
    void addNum(int num) {
        callMedian(num,maxheap,minheap,median);
    }
    
    double findMedian() {
        return median;
    }
};

