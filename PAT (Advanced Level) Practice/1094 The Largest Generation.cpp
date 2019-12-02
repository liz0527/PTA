#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 110;
int cnt[maxn]={0},num=0,layer,maxdepth=0; 
struct node {
	int depth;
	vector<int> child;
}nodes[maxn];
void BFS(int root){
	nodes[root].depth=1;
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		maxdepth = nodes[now].depth;
		cnt[maxdepth]++;
		int size = nodes[now].child.size();
		for(int i=0;i<size;i++){
			nodes[nodes[now].child[i]].depth = maxdepth + 1;
			q.push(nodes[now].child[i]);
		}
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	int id,k,temp;
	for(int i=0;i<m;i++){
		cin >> id >> k;
		for(int j=0;j<k;j++){
			cin >> temp;
			nodes[id].child.push_back(temp);
		}
	}
	BFS(1);
	for(int i=1;i<=maxdepth;i++){
		if(cnt[i]>num){
			num = cnt[i];
			layer = i;
		}
	}
	cout << num << " " << layer;
	return 0;
}