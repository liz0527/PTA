#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1001;
int n,m,k,cur;
vector<int> adj[maxn];
bool vis[maxn]={false};
void DFS(int u){
	if(u==cur) return;
	vis[u] = true;
	for(int i=0;i<adj[u].size();i++){
		int v = adj[u][i];
		if(vis[v]==false){
			DFS(v);
		}
	}
}
int main(){
	cin >> n >> m >> k;
	int s,e;
	for(int i=0;i<m;i++){
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	for(int i=0;i<k;i++){
		cin >> cur;
		for(int j=0;j<maxn;j++){
			vis[j] = false;
		}
		int block = 0;
		for(int j=1;j<=n;j++){
			if(j!=cur && vis[j]==false){
				DFS(j);
				block++;
			}
		}
		cout << block-1 << endl;
	}
	return 0;

}