#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 50010;
int cnt[maxn]={0};
struct node{
	int value,cnt;
	bool operator < (const node &a) const {
		return (cnt!=a.cnt)?cnt>a.cnt:value<a.value;
	}
};
int main(){
	int n,k;
	cin >> n >> k;
	int num;
	set<node> s;
	for(int i=0;i<n;i++){
		cin >> num;
		if(i!=0){
			cout << num << ":";
			int temp=0;
			for(auto it=s.begin();temp<k&&it!=s.end();it++){
				cout << " " << it->value;
				temp++;
			}
			cout << endl;
		}
		auto it = s.find(node{num,cnt[num]});
		if(it!=s.end()) s.erase(it);
		cnt[num]++;
		s.insert(node{num,cnt[num]});
	}
	return 0;
}