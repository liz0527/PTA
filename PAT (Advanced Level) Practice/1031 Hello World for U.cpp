#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main(){
	string input;
	int n1,n2,n3,n;
	cin >> input;
	n = input.length();
	n1 = n3 = floor((n+2)/3);
	n2 = n+2-2*n1;
	for(int i=0;i<n1-1;i++){
		cout << input[i];
		for(int j=0;j<n2-2;j++){
			cout << " ";
		}
		cout << input[n-i-1] << endl;
	}
	for(int i=n1-1;i<n1+n2-1;i++){
		cout << input[i];
	}
	return 0;
}
/*
	也可以先存到二维数组中再输出，这样直接按字符串顺序存放比较方便。
*/