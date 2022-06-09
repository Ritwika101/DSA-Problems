class node{
    public:
    int data;
    int i;
    int j;
    node(int a, int b, int c){
        data=a;
        i=b;
        j=c;
    }
};
class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data>b->data;
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        priority_queue<node*, vector<node*>,compare>pq;
        for(int i=0;i<k;i++){
            node* temp=new node(arr[i][0],i,0);
            pq.push(temp);
        }
        vector<int>v;
        while(pq.size()>0){
            node* temp = pq.top();
            pq.pop();
            int i=temp->i;
            int j=temp->j;
            int data=temp->data;
            v.push_back(data);
            if(j+1<arr[i].size()){
                node* temp_new = new node(arr[i][j+1],i,j+1);
                pq.push(temp_new);
            }
        }
        return v;
    }
};
