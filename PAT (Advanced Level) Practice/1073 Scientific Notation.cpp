#include <iostream>
#include <string>
using namespace std;
int main(){
	string prinum;
	string res="",temp="";
	int len=0,expo=0;
	cin >> prinum;
	//处理正负号
	if(prinum[0]=='-') res = "-";
	prinum = prinum.substr(1);
	//处理数字部分
	while(prinum[len]!='E'){
		if(prinum[len]!='.'){
			temp += prinum[len];
		}
		len++;
	}
	len--;
	//处理指数部分
	prinum = prinum.substr(len+2);
	for(int i=1;i<prinum.length();i++){
		expo = expo*10 + (prinum[i]-'0');
	}
	if(prinum[0]=='-'){
		res += "0.";
		while(expo!=1){
			res += "0";
			expo--;
		}
		res += temp;
	}else {
		if(expo<temp.length()-1){
			temp = temp.substr(0,expo+1)+"."+temp.substr(expo+1);
			res += temp;	
		}else {
			res += temp;
			expo = expo - (len-1);
			while(expo!=0){
				res += "0";
				expo--;
			}
		}
	}
	cout << res;
	return 0;
}