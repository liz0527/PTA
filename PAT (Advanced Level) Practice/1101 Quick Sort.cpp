#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3fffffff; 
int main(){
	int n;
	cin >> n;
	int num[n],left[n],right[n],count=0,pivot[n];
	for(int i=0;i<n;i++){
		cin >> num[i];
	}
	left[0]=0;
	for(int i=1;i<n;i++){
		left[i] = max(left[i-1],num[i-1]);
	}
	right[n-1]=INF;
	for(int i=n-2;i>=0;i--){
		right[i] = min(right[i+1],num[i+1]);
	}
	for(int i=0;i<n;i++){
		if(num[i]>left[i] && num[i]<right[i]) pivot[count++]=num[i];
	}
	cout << count << endl;
	for(int i=0;i<count;i++){
		if(i!=0) cout << " ";
		cout << pivot[i];
	}
    cout << endl;
	return 0;
}