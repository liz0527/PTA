#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int n,minlen=257;
	string suffix="";
	cin >> n;
	getchar();
	string str[n];
	for(int i=0;i<n;i++){
		getline(cin,str[i]);
		int len = str[i].length();
		for(int j=0;j<len/2;j++){
			char temp = str[i][j];
			str[i][j] = str[i][len-j-1];
			str[i][len-j-1] = temp;
		}
		if(len<minlen) minlen=len;
	}
	for(int i=0;i<minlen;i++){
		int flag=1;
		char temp=str[0][i];
		for(int j=1;j<n;j++){
			if(str[j][i]!=temp) flag=0;
		}
		if(flag==0) break;
		else suffix += temp;
	}
	int len = suffix.length();
	for(int i=0;i<len/2;i++){
		char temp = suffix[i];
		suffix[i] = suffix[len-i-1];
		suffix[len-i-1] = temp;
	}
	if(len!=0) cout <<suffix;
	else cout << "nai";
	return 0;
}