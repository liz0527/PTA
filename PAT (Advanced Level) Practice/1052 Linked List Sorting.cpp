#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
	int addr;
	int key;
	int next;
	int flag=0;
};
bool cmp(Node a, Node b){
	if(a.flag==0||b.flag==0){
		return a.flag > b.flag;
	}else {
		return a.key < b.key;
	}
}
int main(){
	int n,priAddr;
	cin >> n >> priAddr;
	Node node[maxn];
	for(int i=0;i<maxn;i++){
		node[i].flag=0;
	}
	int addr,cnt=0;
	for(int i=0;i<n;i++){
		cin >> addr;
		node[addr].addr = addr;
		cin >> node[addr].key >> node[addr].next;
	}
	int p;
	for(p=priAddr;p!=-1;p=node[p].next){
		node[p].flag=1;
		cnt++;
	}
	if(cnt==0){
		printf("0 -1");
	}else {
		sort(node,node+maxn,cmp);
		printf("%d %05d\n",cnt,node[0].addr);
		for(int i=0;i<cnt;i++){
			if(i!=cnt-1) printf("%05d %d %05d\n",node[i].addr,node[i].key,node[i+1].addr);
			else printf("%05d %d -1\n",node[i].addr,node[i].key);
		}
	}
	return 0;
}