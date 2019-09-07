#include <iostream>
#include <string>
using namespace std;
const int maxn = 21;
string ans = "";
struct node {
	int parent=-1;
	string data;
	int lchild,rchild;
}tree[maxn];
void InOrder(int root){
	if(root==-1) return;
	if(!((tree[root].lchild==-1&&tree[root].rchild==-1)||tree[root].parent==-1)) ans += '(';
	InOrder(tree[root].lchild);
	ans += tree[root].data;
	InOrder(tree[root].rchild);
	if(!((tree[root].lchild==-1&&tree[root].rchild==-1)||tree[root].parent==-1)) ans += ')';
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> tree[i].data >> tree[i].lchild >> tree[i].rchild;
		if(tree[i].lchild!=-1) tree[tree[i].lchild].parent = i;
		if(tree[i].rchild!=-1) tree[tree[i].rchild].parent = i;
	}
	int root;
	for(int i=1;i<=n;i++){
		if(tree[i].parent==-1) {
			root = i;
			break;
		}
	}
	InOrder(root);
	cout << ans;
	return 0;
}