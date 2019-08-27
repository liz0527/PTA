#include <iostream>
#include <string>
using namespace std;
int main(){
	string str1,str2;
	bool table[128]={false};
	getline(cin,str1);
	getline(cin,str2);
	int len1=str1.length(),len2=str2.length();
	for(int i=0;i<len2;i++){
		table[str2[i]]=true;
	}
	for(int i=0;i<len1;i++){
		if(table[str1[i]]==false) cout << str1[i];
	}
	return 0;
}