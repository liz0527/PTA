#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,cnt=0;
	cin >> n;
	string user,psw;
	string username[n],password[n];
	for(int i=0;i<n;i++){
		cin >> user >> psw;
		int flag=0;
		for(int j=0;j<psw.length();j++){
			switch(psw[j]){
				case '1':psw[j]='@';flag=1;break;
				case '0':psw[j]='%';flag=1;break;
				case 'l':psw[j]='L';flag=1;break;
				case 'O':psw[j]='o';flag=1;break;
				default:break;
			}
		}
		if(flag==1){
			username[cnt]=user;
			password[cnt]=psw;
			cnt++;
		}
	}
	if(cnt==0){
		if(n==1) cout << "There is 1 account and no account is modified" << endl;
		else cout << "There are " << n << " accounts and no account is modified" << endl;
	}else {
		cout << cnt << endl;
		for(int i=0;i<cnt;i++){
			cout <<username[i] << " " << password[i] << endl;
		}
	}
	return 0;
}