#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,b;
	int z[40],cnt=0;
	string flag="Yes";
	cin >> n >> b;
	do{
		z[cnt++] = n%b;
		n /= b;
	}while(n!=0);
	for(int i=0;i<cnt/2;i++){
		if(z[i]!=z[cnt-i-1]) {
			flag="No";
			break;
		}
	}
	cout << flag << endl;
	for(int i=cnt-1;i>=0;i--){
		cout << z[i];
		if(i!=0) cout << " ";
	}
	return 0;
}