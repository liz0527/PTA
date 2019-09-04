#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main(){
	int m,n,k;
	cin >> m >> n >> k;
	int temp;
	stack<int> st;
	for(int i=0;i<k;i++){
		queue<int> q;
		bool flag=true;
		while(!st.empty()){
			st.pop();
		}
		for(int i=0;i<n;i++){
			cin >> temp;
			q.push(temp);
		}
		for(int i=1;i<=n;i++){
			st.push(i);
			if(st.empty()){
				flag = false;
				break;
			}
			while(!st.empty() && st.top()==q.front()){
				st.pop();
				q.pop();
			}
		}
		if(st.empty() && flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}