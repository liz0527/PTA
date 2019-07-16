#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int main(){
	int m;
	string id,first_id,last_id;
	char sign_in[9],sign_out[9],first_time[]="23:59:59",last_time[]="00:00:00";
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> id >> sign_in >> sign_out;
		if(strcmp(sign_in,first_time)<0){
			strcpy(first_time,sign_in);
			first_id = id;
		}
		if(strcmp(sign_out,last_time)>0){
			strcpy(last_time,sign_out);
			last_id = id;
		}
	}
	cout << first_id << " " << last_id;
	return 0;
}
/* 
	strcpy-用一个字符数组给另一个赋值
	strcmp-比较两个字符数组字典序
 */