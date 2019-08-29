#include <iostream>
using namespace std;
int main(){
	int n,ans=0;
	cin >> n;
	int floor[n+1];
	floor[0]=0;
	for(int i=1;i<=n;i++){
		cin >> floor[i];
		ans += (floor[i]-floor[i-1])>0?(floor[i]-floor[i-1])*6:(floor[i-1]-floor[i])*4;
		ans += 5;
	}
	cout << ans;
	return 0;
}