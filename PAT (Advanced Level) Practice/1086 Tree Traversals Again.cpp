#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int maxn = 50;
int pre[maxn],in[maxn],n,num=0;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
node* create(int preL, int preR, int inL, int inR){
	if(preL>preR) return NULL;
	node* root = new node;
	root->data = pre[preL];
	int k;
	for(k=inL;k<=inR;k++){
		if(pre[preL]==in[k]) break;
	}
	int numLeft = k-inL;
	root->lchild = create(preL+1,preL+numLeft,inL, k-1);
	root->rchild = create(preL+numLeft+1, preR, k+1,inR);
	return root;
}
void postOrder(node* root){
	if(root==NULL) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	if(num!=0) cout << " ";
	cout << root->data;
	num++;
}
int main(){
	int temp,cntpre=0,cntin=0;
	stack<int> st;
	cin >> n;
	string str;
	for(int i=0;i<2*n;i++){
		cin >> str;
		if(str=="Push") {
			cin >> temp;
			st.push(temp);
			pre[cntpre++] = temp;
		}else if(str=="Pop"){
			in[cntin++] = st.top();
			st.pop();
		}
	}
	node* root = create(0,n-1,0,n-1);
	postOrder(root);
	return 0;
}