#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100010;
int n,cnt=0;
double p,r,maxp=0;
struct node {
	vector<int> child;
}nodes[maxn];
void DFS(int root, double price){
	if(nodes[root].child.size()==0) {
		if(price>maxp){
			maxp = price;
			cnt =1;
		}
		else if(price==maxp){
			cnt++;
		}
		return;
	}
	for(int i=0;i<nodes[root].child.size();i++){
		DFS(nodes[root].child[i],price*(1+r*0.01));
	}
}
int main(){
	int root,temp;
	cin >> n >> p >> r;
	for(int i=0;i<n;i++){
		cin >> temp;
		if(temp==-1) root = i;
		else nodes[temp].child.push_back(i);
	}
	DFS(root,p);
	printf("%.2f %d",maxp,cnt);
	return 0;
}