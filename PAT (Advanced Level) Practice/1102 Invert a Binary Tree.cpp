#include <iostream>
#include <queue> 
#include <string>
using namespace std;
int n,maxn=12,count=0;
struct node {
	int data;
	int lchild=-1;
	int rchild=-1;
	int parent=-1;
};
node nodes[12];
void layerorder(int root){
	int cnt=0;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(cnt!=0) cout << " ";
		cout << now;
		cnt++;
		if(nodes[now].lchild!=-1) q.push(nodes[now].lchild);
		if(nodes[now].rchild!=-1) q.push(nodes[now].rchild);
	}
}
void inorder(int root){
	if(root==-1) return;
	inorder(nodes[root].lchild);
	if(count!=0) cout << " ";
	cout << root;
	count++;
	inorder(nodes[root].rchild);
}
int main(){
	int root;
	char lin, rin;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> rin >> lin;
		if(rin != '-') {
			nodes[i].rchild = (int)(rin-'0');
			nodes[rin-'0'].parent = i;
		}
		if(lin != '-') {
			nodes[i].lchild = (int)(lin-'0');
			nodes[lin-'0'].parent = i;
		}
	}
	for(int i=0;i<n;i++){
		if(nodes[i].parent==-1) root = i;
	}
	layerorder(root);
	cout << endl;
	inorder(root);
	return 0;
}