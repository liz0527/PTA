#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int k;
	int n;
	double a;
	scanf("%d",&k);
	double term[1001]={};
	for(int i=0;i<k;i++){
		scanf("%d %lf",&n,&a);
		term[n] = a;
	}
	scanf("%d",&k);
	double res[2001]={};
	for(int i=0;i<k;i++){
		scanf("%d %lf",&n,&a);
		for(int j=0;j<1001;j++){
			if(term[j]!=0)
				res[n+j] += a*term[j];
		}
	}
	int count=0;
	for(int i=0;i<2001;i++){
		if(res[i]!=0) count++;
	}
	printf("%d",count);
	for(int i=2000;i>=0;i--){
		if(res[i]!=0)
			printf(" %d %.1f",i,res[i]);
	}
	return 0;
}