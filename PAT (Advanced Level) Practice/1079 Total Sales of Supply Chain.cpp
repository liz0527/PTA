#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n;
const int maxn=100010;
double p,r,res=0.0;
struct node {
	int cnt=0;
	vector<int> child;
}nodes[maxn];
void DFS(int root, double price){
	int size = nodes[root].child.size();
	if(size==0) {
		res += nodes[root].cnt*price;
		return;
	}
	for(int i=0;i<size;i++){
		DFS(nodes[root].child[i],price*(1+r*0.01));
	}	
}
int main(){
	int temp,tchild;
	cin >> n >> p >> r;
	for(int i=0;i<n;i++){
		cin >> temp;
		if(temp==0) {
			cin >> tchild;
			nodes[i].cnt = tchild;
		}else {
			for(int j=0;j<temp;j++){
				cin >> tchild;
				nodes[i].child.push_back(tchild);
			}
		}
	}
	DFS(0,p);
	printf("%.1f",res);
	return 0;
}