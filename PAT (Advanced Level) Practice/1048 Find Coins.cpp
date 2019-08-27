#include <iostream>
using namespace std;
int main(){
	int n,m,temp;
	int coin[1001]={0};
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> temp;
		coin[temp]++;
	}
	for(int i=1;i<m;i++){
		if((i!=m-i && coin[i]!=0 && coin[m-i]!=0)||(i==m-i && coin[i]>1)){
			cout << i << " " << m-i;
			return 0;
		}
	}
	cout << "No Solution";
	return 0;
}