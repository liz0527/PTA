#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
const int INF = 0x7fffffff;
struct Node{
	int addr,data,next,flag;
}node[maxn];
bool cmp(Node a, Node b){
	return a.flag < b.flag;
}
int main(){
	for(int i=0;i<maxn;i++){
		node[i].flag = INF;
	}
	int priAddr,n,addr;
	cin >> priAddr >> n;
	bool num[10010]={false};
	for(int i=0;i<n;i++){
		cin >> addr;
		node[addr].addr = addr;
		cin >> node[addr].data >> node[addr].next;
	}
	int cnt=0,cntValid=0,cntRemoved=0;
	for(int p=priAddr;p!=-1;p=node[p].next){
		if(num[abs(node[p].data)]==true){
			node[p].flag = maxn + cntRemoved++;
		}else{
			num[abs(node[p].data)] = true;
			node[p].flag = cntValid++;
		}
	}
	cnt = cntValid + cntRemoved;
	sort(node,node+maxn,cmp);
	if(cnt==0) {
		printf("0 -1\n");
		return 0;
	}
	sort(node,node+cnt,cmp);
	for(int i=0;i<cntValid;i++){
		if(i!=cntValid-1) printf("%05d %d %05d\n",node[i].addr,node[i].data,node[i+1].addr);
		else printf("%05d %d -1\n",node[i].addr,node[i].data);
	}
	for(int i=cntValid;i<cnt;i++){
		if(i!=cnt-1) printf("%05d %d %05d\n",node[i].addr,node[i].data,node[i+1].addr);
		else printf("%05d %d -1\n",node[i].addr,node[i].data);
	}
	return 0;
}