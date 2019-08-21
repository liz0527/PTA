#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
int main(){
	string str1,str2,broken="";
	cin >> str1 >> str2;
	int i=0,j=0;
	while(i<str1.length()){
		if(str1[i]!=str2[j]){
			int flag=0;
			for(int k=0;k<broken.length();k++){
				if(broken[k]==toupper(str1[i])){
					flag=1;
				}
			}
			if(flag==0) broken += toupper(str1[i]);
			i++;
		}else{
			i++;
			j++;
		}
	}
	cout << broken;
	return 0;
}