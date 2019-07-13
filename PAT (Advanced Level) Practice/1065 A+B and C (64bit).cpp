#include <iostream>
using namespace std;
int main(){
	int T;
	long long a,b,c,res;
	cin >> T;
	for(int i=1;i<=T;i++){
		string flag;
		cin >> a >> b >> c;
		res = a + b;
		if(a>0 && b>0 && res<0) flag = "true";
		else if(a<0 && b<0 && res>=0) flag = "false";
		else if(res > c) flag = "true";
		else flag = "false";
		
		cout << "Case #" << i << ": " << flag << endl;
	}
	return 0;
}