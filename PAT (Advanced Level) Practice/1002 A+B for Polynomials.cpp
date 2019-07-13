#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int k;
	double term[1001]={};
	int n;
	double a;
	int count=0;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %lf",&n,&a);
		term[n] = a;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %lf",&n,&a);
		term[n] += a;
	}
	for(int i=0;i<1001;i++){
		if(term[i]!=0) count++;
	}
	printf("%d",count);
	for(int i=1000;i>=0;i--){
		if(term[i]!=0) 
			printf(" %d %.1f",i,term[i]);
	}
	return 0;
}