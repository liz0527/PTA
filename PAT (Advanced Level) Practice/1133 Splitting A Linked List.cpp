#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100010;
const int INF = 0x7fffffff;
struct node{
	int addr,data,next;
}link[maxn];
vector<int> vi;
int main(){
	int n,k,priNode;
	scanf("%d %d %d",&priNode,&n,&k);
	int addr;
	for(int i=0;i<n;i++){
		scanf("%d",&addr);
		link[addr].addr = addr;
		scanf("%d %d", &link[addr].data, &link[addr].next);
	}
	int p,negCnt=0,bigCnt=0;
	for(p = priNode;p!=-1;p=link[p].next){
		if(link[p].data<0){//是负数去队首
			vi.insert(vi.begin()+negCnt++,p);
		}else if(link[p].data>k){
			vi.push_back(p);
		}else {
			vi.insert(vi.begin()+negCnt+bigCnt++,p);
		}
	}
	for(int i=0;i<vi.size();i++){
		if(i!=vi.size()-1){
			printf("%05d %d %05d\n",link[vi[i]].addr,link[vi[i]].data,link[vi[i+1]].addr);
		}else {
			printf("%05d %d -1\n",link[vi[i]].addr,link[vi[i]].data);
		}
	}
	return 0;
}