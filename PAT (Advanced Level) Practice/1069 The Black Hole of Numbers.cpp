#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
void to_array(int n, int num[]){
	for(int i=0;i<4;i++){
		num[i] = n%10;
		n /= 10;
	}
}
int to_number(int num[]){
	int ans=0;
	for(int i=0;i<4;i++){
		ans = ans*10 + num[i];
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	int num[4],upper,lower;
	while(1){
		to_array(n,num);
		sort(num,num+4);
		lower = to_number(num);
		sort(num,num+4,cmp);
		upper = to_number(num);
		n = upper-lower;
		printf("%04d - %04d = %04d\n",upper,lower,n);
        if(n==6174 || n==0) break;
	}
	return 0;
}