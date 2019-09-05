#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1010;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
vector<int> origin,pre,preM,post,postM;
void insert(node* &root, int x){
	if(root==NULL){
		root = new node;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}
	if(root->data <= x) insert(root->rchild,x);
	else insert(root->lchild,x);
}
void preOrder(node* root,vector<int>&v){
	if(root==NULL) return;
	v.push_back(root->data);
	preOrder(root->lchild,v);
	preOrder(root->rchild,v);
}
void preOrderMirror(node* root,vector<int>&v){
	if(root==NULL) return;
	v.push_back(root->data);
	preOrderMirror(root->rchild,v);
	preOrderMirror(root->lchild,v);
}
void postOrder(node* root,vector<int>&v){
	if(root==NULL) return;
	postOrder(root->lchild,v);
	postOrder(root->rchild,v);
	v.push_back(root->data);
}
void postOrderMirror(node* root,vector<int>&v){
	if(root==NULL) return;
	postOrderMirror(root->rchild,v);
	postOrderMirror(root->lchild,v);
	v.push_back(root->data);
}
int main(){
	int n,data;
	cin >> n;
	node* root = NULL;
	for(int i=0;i<n;i++){
		cin >> data;
		origin.push_back(data);
		insert(root,data);
	}
	preOrder(root,pre);
	preOrderMirror(root,preM);
	if(origin == pre){
		cout << "YES" << endl;
		postOrder(root,post);
		for(int i=0;i<n;i++){
			if(i!=0) cout << " ";
			cout << post[i];
		}
	}else if(origin == preM){
		cout << "YES" << endl;
		postOrderMirror(root,postM);
		for(int i=0;i<n;i++){
			if(i!=0) cout << " ";
			cout << postM[i];
		}
	}else cout << "NO" << endl;
	return 0;

}