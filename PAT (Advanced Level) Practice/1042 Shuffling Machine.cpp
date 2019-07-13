#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int k;//重复次数
	string num[13]={"13","1","2","3","4","5","6","7","8","9","10","11","12"};
	int order[55];//排列方式
	string start[55],end[55];//初始顺序，排后顺序
	scanf("%d",&k);
	for(int i=0;i<54;i++){
		scanf("%d",&order[i+1]);
	}
	for(int i=1;i<55;i++){
		if((i-1)/13==0) start[i]="S"+num[i%13];
		else if((i-1)/13==1) start[i]="H"+num[i%13];
		else if((i-1)/13==2) start[i]="C"+num[i%13];
		else if((i-1)/13==3) start[i]="D"+num[i%13];
		else if(i==53) start[i]="J1";
		else start[i]="J2";
	}
	while(k--){
		for(int i=1;i<55;i++){
			end[order[i]]=start[i];
		}
		for(int i=1;i<55;i++){
			start[i]=end[i];
		}
	}
	for(int i=1;i<55;i++){
		if(i!=1) printf(" ");
		cout << end[i];
	}
	return 0;
}

/*
	1. 初始化牌组start[55]，根据i与13的关系
	2. 将排列顺序存入数组order[55]
	3. 模拟关系：end[order[i]]=start[i]
	4. 令start=end，再进行下一次排列
*/