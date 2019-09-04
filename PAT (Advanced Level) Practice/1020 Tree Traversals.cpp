#include <iostream>
#include <queue>
using namespace std;
const int maxn = 50;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
int in[maxn],post[maxn],n,num=0;
node* create(int postL, int postR, int inL, int inR){
	if(postL>postR) return NULL;
	node* root = new node;
	root->data = post[postR];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==post[postR]) break;
	}
	int numLeft = k-inL;
	root->lchild = create(postL, postL+numLeft-1,inL,k-1);
	root->rchild = create(postL+numLeft,postR-1,k+1,inR);
	return root;
}
void layerOrder(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* front = q.front();
		q.pop();
		cout << front->data;
		num++;
		if(num<n) cout << " ";
		if(front->lchild!=NULL) q.push(front->lchild);
		if(front->rchild!=NULL) q.push(front->rchild);
	}
}
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> post[i];
	}
	for(int i=0;i<n;i++){
		cin >> in[i];
	}
	node* root = create(0,n-1,0,n-1);
	layerOrder(root);
	return 0;
}