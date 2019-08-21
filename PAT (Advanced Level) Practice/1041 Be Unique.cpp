#include <iostream>
using namespace std;
int main(){
	int n,cnt[10001]={0},flag=0;
	cin >> n;
	int num[n]; 
	for(int i=0;i<n;i++){
		cin >> num[i];
		cnt[num[i]]++;
	}
	for(int i=0;i<n;i++){
		if(cnt[num[i]]==1){
			cout << num[i];
			flag=1;
			break;
		}
	}
	if(flag==0) cout << "None";
	return 0;

}