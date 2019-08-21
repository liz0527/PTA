#include <iostream>
#include <string>
using namespace std;
int main(){
	string str1,str2;
	int cnt[62]={0},extra=0,miss=0;
	cin >> str1 >> str2;
	for(int i=0;i<str2.length();i++){
		if(str2[i]>='0'&&str2[i]<='9') cnt[str2[i]-'0']++;
		if(str2[i]>='a'&&str2[i]<='z') cnt[str2[i]-'a'+10]++;
		if(str2[i]>='A'&&str2[i]<='Z') cnt[str2[i]-'A'+36]++;
	}
	for(int i=0;i<str1.length();i++){
		if(str1[i]>='0'&&str1[i]<='9') cnt[str1[i]-'0']--;
		if(str1[i]>='a'&&str1[i]<='z') cnt[str1[i]-'a'+10]--;
		if(str1[i]>='A'&&str1[i]<='Z') cnt[str1[i]-'A'+36]--;
	}
	for(int i=0;i<62;i++){
		if(cnt[i]>0) miss += cnt[i];
		if(cnt[i]<0) extra -= cnt[i];
	}
	if(miss>0) cout << "No " << miss;
	else cout << "Yes " << extra;
	return 0;
}