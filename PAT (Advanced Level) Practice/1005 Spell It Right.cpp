#include <iostream>
#include <string>
using namespace std;
int main(){
	string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	string n;
	int res=0,sum[10];
	cin >> n;
	for(int i=0;i<n.length();i++){
		res += (n[i]-'0');
	}
	int cnt=0;
	if(res==0) cout << "zero";
	else {
		while(res!=0){
			sum[cnt++] = res%10;
			res /= 10;
		}
		for(int i=cnt-1;i>=0;i--){
			cout << num[sum[i]];
			if(i!=0) cout << " ";
		}
	}
	return 0;

}
/*
	注意0的情况
*/
