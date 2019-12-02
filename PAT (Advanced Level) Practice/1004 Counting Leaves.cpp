#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn=110;
int n,m,cnt[maxn]={0},maxdepth=0;
struct node{
	int depth;
	vector<int> child;
}nodes[maxn];
void layer(int root){
	nodes[root].depth=0;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		int size = nodes[now].child.size();
		maxdepth = nodes[now].depth;
		if(size==0) cnt[nodes[now].depth]++;
		else {
			for(int i=0;i<size;i++){
				nodes[nodes[now].child[i]].depth = nodes[now].depth + 1;
				q.push(nodes[now].child[i]);
			}
		}
	}
}
int main(){
	cin >> n >> m;
	if(n==1) {
		cout << "1";
		return 0;
	}
	int id,k,temp;
	for(int i=0;i<m;i++){
		cin >> id >> k;
		for(int j=0;j<k;j++){
			cin >> temp;
			nodes[id].child.push_back(temp);
		}
	}
	layer(1);
	for(int i=0;i<=maxdepth;i++){
		if(i!=0) cout << " ";
		cout << cnt[i];
	}
	return 0;
}