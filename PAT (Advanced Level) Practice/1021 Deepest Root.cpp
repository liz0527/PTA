#include <iostream>
#include <vector>
using namespace std;
const int maxn = 10010;
int n,cnt=0,maxdepth=0,nowdepth;
vector<int> adj[maxn];
bool vis[maxn]={false};
int length[maxn]={0};
void DFS(int v,int depth){
	vis[v] = true;
	cnt++;
	if(nowdepth<depth) nowdepth = depth;
	for(int i=0;i<adj[v].size();i++){
		int u = adj[v][i];
		if(vis[u]==false){
			DFS(u,depth+1);
		}
	}
}
int main(){
	cin >> n;
	int u,v;
	for(int i=1;i<n;i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		cnt = 0;
		nowdepth = 0;
		for(int j=1;j<=n;j++){
			vis[j]=false;
		}
		DFS(i,1);
		if(cnt==n){
			length[i] = nowdepth;
			if(nowdepth>maxdepth) maxdepth = nowdepth;
		}
	}
	if(maxdepth==0) {
		for(int j=0;j<=n;j++){
			vis[j]=false;
		}
		int block = 0;
		for(int i=1;i<=n;i++){
			if(vis[i]==false){
				DFS(i,1);
				block++;
			}
		}
		cout << "Error: " << block << " components" << endl;
	}
	else {
		for(int i=1;i<=n;i++){
			if(length[i]==maxdepth) cout << i << endl;
		}
	}
	return 0;
}