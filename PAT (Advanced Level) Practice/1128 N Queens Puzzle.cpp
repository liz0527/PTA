#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int k,n;
	cin >> k;
	for(int i=0;i<k;i++){
		cin >> n;
		int queen[n+1],flag=1;
		for(int j=1;j<=n;j++){
			cin >> queen[j];
		}
		for(int j=1;j<=n;j++){
			for(int m=j+1;m<=n;m++){
				if(queen[m]==queen[j]||abs(m-j)==abs(queen[m]-queen[j])){
					flag=0;
					break;
				}
			}
		}
		if(flag==1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}