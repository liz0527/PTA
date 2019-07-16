#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	double res=1.0;
	int mark;
	char status[3] = {'W', 'T', 'L'};
	double info[3],max[3]={};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			scanf("%lf",&info[j]);
			if(info[j]>=max[i]) {
				max[i]=info[j];
				mark=j;
			}
		}
		printf("%c ",status[mark]);
		res *= max[i];
	}
	res = (res*0.65-1)*2;
	printf("%.2f",res);
	return 0;
}