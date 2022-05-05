
void printRightView(Node* root){
	if(!root)
		return;
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		for(int i=1;i<=n;i++){
			Node* temp = q.front();
			if(i == n)
				cout<<temp->data<<" ";
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}
