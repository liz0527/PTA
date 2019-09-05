#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 110;
int n,m,s;
int path[maxn];
struct node{
	int w;
	vector<int> child;
}Node[maxn];
bool cmp(int a, int b){
	return Node[a].w > Node[b].w;
}
void DFS(int index, int sum, int numNode){
	if(sum > s) return;
	if(sum == s){
		if(Node[index].child.size()!=0) return;
		for(int i=0;i<numNode;i++){
			cout << Node[path[i]].w;
			if(i<numNode-1) cout << " ";
			else cout << endl;
		}
		return;
	}
	for(int i=0;i<Node[index].child.size();i++){
		int child = Node[index].child[i];
		path[numNode] = child;
		DFS(child,sum+Node[child].w,numNode+1);
	}
}
int main(){
	cin >> n >> m >> s;
	for(int i=0;i<n;i++){
		cin >> Node[i].w;
	}
	int id,k,temp;
	for(int i=0;i<m;i++){
		cin >> id >> k;
		for(int j=0;j<k;j++){
			cin >> temp;
			Node[id].child.push_back(temp);
		}
		sort(Node[id].child.begin(),Node[id].child.end(),cmp);
	}
	path[0]=0;
	DFS(0,Node[0].w,1);
	return 0;
}