#include <iostream>
#include <string>
using namespace std;
int n;
string deal(string s, int&e){
	int k=0;
	while(s.length()>0 && s[0]=='0'){//去掉前导0
		s.erase(s.begin());
	}
	if(s[0]=='.'){//去掉小数点以及其后的0
		s.erase(s.begin());
		while(s.length()>0 && s[0]=='0'){
			s.erase(s.begin());
			e--;//处理指数
		}
	}else {
		while(k<s.length() && s[k]!='.'){
			k++;
			e++;
		}
		if(k<s.length()){
			s.erase(s.begin()+k);
		}
	}
	if(s.length()==0){
		e=0;
	}
	int num=0;
	k=0;
	string res;
	while(num<n){
		if(k<s.length()) res+=s[k++];
		else res += '0';
		num++;
	}
	return res;
}
int main(){
	int e1=0,e2=0;
	string a,b,s1,s2;
	cin >> n >> a >> b;
	s1 = deal(a,e1);
	s2 = deal(b,e2);
	if(s1==s2 && e1==e2){
		cout << "YES 0." << s1 << "*10^" << e1 << endl;
	}else {
		cout << "NO 0." << s1 << "*10^" << e1 << " 0." << s2 << "*10^" << e2 << endl;
	}
	return 0;
}