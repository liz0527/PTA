#include <iostream>
#include <cstdio>
#include <ctype.h>
#include <string>
using namespace std;
int main(){
	string weekItem[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	string first,second;
	int week,hour,min;
	int i;
	cin >> first >> second;
	for(i=0;i<first.length()&&i<second.length();i++){
		if(first[i]==second[i] && first[i]>='A'&& first[i]<='G'){
			week = first[i]-'A';
			break;
		}
	}
	for(i++;i<first.length()&&i<second.length();i++){
		if(first[i]==second[i]){
			if(first[i]>='0'&&first[i]<='9') {
				hour = first[i]-'0';
				break;
			}
			else if((first[i]>='A'&& first[i]<='N')) {
				hour = first[i]-'A'+10;
				break;
			}
		}
	}
	cin >> first >> second;
	for(i=0;i<first.length()&&i<second.length();i++){
		if(first[i]==second[i]){
			if((first[i]>='a'&& first[i]<='z')||(first[i]>='A'&& first[i]<='Z')){
				min = i;
				break;
			}
		}
	}
	cout << weekItem[week] << " ";
	printf("%02d:%02d",hour,min);
	return 0;
}
/*
	注意各自的范围
	星期几：A-G
	小时：0-9 A-N
	分钟：a-z A-Z
*/