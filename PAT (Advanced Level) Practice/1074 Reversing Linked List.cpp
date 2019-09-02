#include <iostream>
#include <algorithm>
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
	int priAddr,n,k,addr,cnt=1;
	cin >> priAddr >> n >> k;
	for(int i=0;i<n;i++){
		cin >> addr;
		node[addr].addr = addr;
		cin >> node[addr].data >> node[addr].next;
	}
	for(int p=priAddr;p!=-1;p=node[p].next){
		node[p].flag = cnt++;
	}
	cnt--;
	if(cnt==0) {
		printf("0 -1\n");
		return 0;
	}
	sort(node,node+maxn,cmp);
	for(int i=0;i<cnt;i+=k){
		if(i+k<=cnt) reverse(node+i,node+i+k);
	}
	for(int i=0;i<cnt;i++){
		if(i!=cnt-1) printf("%05d %d %05d\n",node[i].addr,node[i].data,node[i+1].addr);
		else printf("%05d %d -1\n",node[i].addr,node[i].data);
	}
}