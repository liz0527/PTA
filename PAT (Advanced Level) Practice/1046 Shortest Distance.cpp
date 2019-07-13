#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int n,dis[100001],sum=0,d;
	int m,start,end;
	scanf("%d",&n);
	dis[1]=0;
	for(int i=1;i<n+1;i++){
		scanf("%d",&d);
		sum += d;
		dis[i+1] = sum;
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&start,&end);
		if(end<start){
			int temp = end;
			end = start;
			start = temp;
		}
		int res = (dis[end]-dis[start])<=(sum-(dis[end]-dis[start]))?(dis[end]-dis[start]):(sum-(dis[end]-dis[start]));
		printf("%d\n",res);
	}
	return 0;
}
/*
	直接存储从1号结点到每个结点的距离
*/