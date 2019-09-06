#include <iostream>
#include <vector>
using namespace std;
const int maxv = 510;
const int INF = 0x7fffffff;
int n,m,s,e;
int d[maxv],map[maxv][maxv],cost[maxv][maxv];
bool vis[maxv]={false};
vector<int> pre[maxv];
vector<int> path,tempPath;
int optvalue = INF;
void Dijkstra(int s){
	fill(d,d+maxv,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false && d[j]<min){
				u = j;
				min = d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false && map[u][v]!=INF){
				if(d[u]+map[u][v]<d[v]){
					d[v] = d[u]+map[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+map[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int v){
	if(v==s){
		tempPath.push_back(v);
		int value=0;
		for(int i=tempPath.size()-1;i>0;i--){
			value += cost[tempPath[i]][tempPath[i-1]];
		}
		if(value < optvalue){
			optvalue = value;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}
int main(){
	int u,v;
	cin >> n >> m >> s >> e;
	fill(map[0],map[0]+maxv*maxv,INF);
	fill(cost[0],cost[0]+maxv*maxv,INF);
	for(int i=0;i<m;i++){
		cin >> u >> v;
		cin >> map[u][v] >> cost[u][v];
		map[v][u] = map[u][v];
		cost[v][u] = cost[u][v];
	}
	Dijkstra(s);
	DFS(e);
	for(int i=path.size()-1;i>=0;i--){
		cout << path[i] << " ";
	}
	cout << d[e] << " " << optvalue;
	return 0;
}