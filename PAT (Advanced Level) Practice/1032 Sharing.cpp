#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
	int next;
	bool flag;
}
int main(){
	int addr1,addr2,n;
	cin >> addr1 >> addr2 >> n;
	Node node[maxn];
	int addr,next;
	char data;
	for(int i=0;i<n;i++){
		cin >> addr >> data >> next;
		node[addr].next = next;
	}
	int p;
	for(p=addr1;p!=-1;p=node[p].next){
		node[p].flag=true;
	}
	for(p=addr2;p!=-1;p=node[p].next){
		if(node[p].flag==true) break;
	}
	if(p!=-1) printf("%05d",p);
	else printf("-1");
	return 0;
}
	