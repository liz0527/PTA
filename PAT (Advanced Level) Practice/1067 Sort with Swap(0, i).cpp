#include <iostream>
using namespace std;
int check(int pos[],int n,int now){//检查每个数是否在自己的位置上。若不在，返回这个数。若在，返回-1。
	for(int i=now;i<n;i++){
		if(pos[i]!=i) return i;
	}
	return -1;
}
int main(){
	int n,temp,cnt=0;
	cin >> n;
	int pos[n],left=n-1;
	for(int i=0;i<n;i++){
		cin >> temp;
		pos[temp]=i;
		if(temp==i && temp!=0) left--;
	}
	int now=1;
	while(left>0){
		if(pos[0]==0){
			now = check(pos,n,now);
			int t = pos[0];
			pos[0] = pos[now];
			pos[now] = t;
			cnt++;
		}
		temp = pos[0];
		pos[0] = pos[temp];
		pos[temp] = temp;
		left--;
		cnt++;
	}
	cout << cnt;
	return 0;
}
//当0在本位时，寻找下一个不在本位的数交换，要记录这个数，下一次从这个数开始继续寻找，减少不必要的次数。