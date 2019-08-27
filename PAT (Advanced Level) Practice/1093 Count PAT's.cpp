#include <iostream>
#include <string>
using namespace std;
const int MOD = 1000000007;
int main(){
	string input;
	cin >> input;
	int len = input.length();
	int leftp[len],right=0,ans=0;
	if(input[0]=='P') leftp[0]=1;
	else leftp[0]=0;
	for(int i=1;i<len;i++){
		if(input[i]=='P') leftp[i]=leftp[i-1]+1;
		else leftp[i]=leftp[i-1];
	}
	for(int i=len-1;i>=0;i--){
		if(input[i]=='T') right++;
		else if(input[i]=='A') ans = (ans + right*leftp[i])%MOD;
	}
	cout << ans;
	return 0;
}