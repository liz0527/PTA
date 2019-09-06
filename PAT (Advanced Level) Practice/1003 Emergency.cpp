#include <iostream>
using namespace std;
const int maxv = 510;
const int INF = 0x7fffffff;
int n;
int map[maxv][maxv],d[maxv];
int weight[maxv],w[maxv]={0};
int num[maxv]={0};
bool vis[maxv]={false};
void Dijkstra(int s){
	fill(d,d+maxv,INF);
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
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
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}else if(d[u]+map[u][v]==d[v]){
					if(w[u] + weight[v]>w[v]) w[v] = w[u] + weight[v];
					num[v] += num[u];
				}
			}
		}
	}
}
int main(){
	int m,s,e,c1,c2,len;
	cin >> n >> m >> s >> e;
	for(int i=0;i<n;i++){
		cin >> weight[i];
	}
	fill(map[0],map[0]+maxv*maxv,INF);
	for(int i=0;i<m;i++){
		cin >> c1 >> c2 >> len;
		map[c1][c2] = map[c2][c1] = len;
	}
	Dijkstra(s);
	cout << num[e] << " " << w[e] << endl;
	return 0;
}