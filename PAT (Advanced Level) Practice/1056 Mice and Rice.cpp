#include <iostream>
#include <queue>
using namespace std;
struct Node{
	int order,weight;
};
int main(){
	int n,m,order;
	cin >> n >> m;
	Node node[n];
	for(int i=0;i<n;i++){
		cin >> node[i].weight;
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		cin >> order;
		q.push(order);
	}
	int temp = n,group;
	while(q.size()!=1){
		if(temp%m == 0) group = temp/m;
		else group = temp/m + 1;
		for(int i=0;i<group;i++){
			int k = q.front();
			for(int j=0;j<m;j++){
				if(i*m+j>=temp) break;
				int front = q.front();
				if(node[front].weight > node[k].weight) k=front;
				node[front].order = group+1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	node[q.front()].order = 1;
	for(int i=0;i<n;i++){
		cout << node[i].order;
		if(i<n-1) cout << " ";
	}
	return 0;
}