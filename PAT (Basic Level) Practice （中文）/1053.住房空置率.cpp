#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n,d,k;
	double e,temp;
	int may_empty=0,empty=0;
	cin >> n >> e >> d;
	for(int i=0;i<n;i++){
		cin >> k;
		int count=0;
		for(int j=0;j<k;j++){
			cin >> temp;
			if(temp<e) count++;
		}
		if(count > k/2){
			if(k>d) empty++;
			else may_empty++;
		}
	}
	double may,must;
	may = (double)may_empty/n*100;
	must = (double)empty/n*100;
	printf("%.1f%% %.1f%%",may,must);
	return 0;
}