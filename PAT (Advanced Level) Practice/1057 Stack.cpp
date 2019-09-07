#include <iostream>
#include <stack>
#include <string>
using namespace std;
const int maxn = 100010;
const int sqrt = 316;
stack<int> st;
int block[sqrt]={0};
int table[maxn]={0};
void Pop(){
	int x = st.top();
	st.pop();
	block[x/sqrt]--;
	table[x]--;
	cout << x << endl;
}
void Push(int x){
	st.push(x);
	block[x/sqrt]++;
	table[x]++;
}
void PeekMedian(int k){
	int sum=0;
	int idx=0;
	while(sum+block[idx]<k){
		sum += block[idx++];
	}
	int num = idx*sqrt;
	while(sum + table[num]<k){
		sum += table[num++];
	}
	cout << num << endl;
}
int main(){
	int n,key;
	string opt;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> opt;
		if(opt=="Push"){
			cin >> key;
			Push(key);
		}else if(opt=="Pop"){
			if(st.empty()){
				cout << "Invalid" << endl;
			}else {
				Pop();
			}
		}else {
			if(st.empty()){
				cout << "Invalid" << endl;
			}else {
				int k = st.size();
				if(k%2==0) k = k/2;
				else k = (k+1)/2;
				PeekMedian(k);
			}

		}
	}
	return 0;
}