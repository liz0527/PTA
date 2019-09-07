#include <iostream>
#include <string>
using namespace std;
int stringToNum(string s){
	int num=0;
	for(int i=0;i<s.length();i++){
		num = num*10 + (s[i]-'0');
	}
	return num;
}
int main(){
	int n;
	string z,z1,z2;
	cin >> n;
	int len,a,b,c;
	for(int i=0;i<n;i++){
		cin >> z;
		len = z.length()/2;
		z1 = z.substr(0,len);
		z2 = z.substr(len);
		a = stringToNum(z1);
		b = stringToNum(z2);
		c = stringToNum(z);
		if(a*b!=0&&c%(a*b)==0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}