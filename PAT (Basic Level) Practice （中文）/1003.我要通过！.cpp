#include <iostream>
#include <map>
using namespace std;
int main(){
	int n;
	cin >> n;
	int p,t;
	string s;
	for(int i=0;i<n;i++){
		cin >> s;
		map<char,int> m;
		for(int j=0;j<s.length();j++){
			m[s[j]]++;
			if(s[j]=='P') p=j;
			if(s[j]=='T') t=j;
			//p记录P的位置，t记录T的位置，p即为P之前A的个数，s.length()-t-1即为T之后A的个数，t-p-1即为P和T之间A的个数
		}
		if(m['P']==1 && m['T']==1 && m['A']!=0 && m.size()==3 && (t-p)!=1 && (t-p-1)*p == s.length()-t-1){
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}