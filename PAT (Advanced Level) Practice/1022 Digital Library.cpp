#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
void query(map<string,set<int>> &mp, string &str){
	if(mp.find(str)==mp.end()) {
		cout << "Not Found" << endl;
		return;
	}
	for(set<int>::iterator it=mp[str].begin();it!=mp[str].end();it++){
		printf("%07d\n",*it);
	}
}
int main(){
	map<string,set<int>> title;
	map<string,set<int>> author;
	map<string,set<int>> publisher;
	map<string,set<int>> year;
	map<string,set<int>> keywords;
	int n,m;
	cin >> n;
	string tYear,tTitle,tAuthor,tPub,tKey;
	int tId;
	for(int i=0;i<n;i++){
		cin >> tId;
		char c = getchar();
		getline(cin,tTitle);title[tTitle].insert(tId);
		getline(cin,tAuthor);author[tAuthor].insert(tId);
		while(cin >> tKey){
			keywords[tKey].insert(tId);
			c = getchar();
			if(c=='\n') break;
		}
		getline(cin,tPub);publisher[tPub].insert(tId);
		getline(cin,tYear);year[tYear].insert(tId);
	}
	cin >> m;

	string temp;int type;
	for(int i=0;i<m;i++){
		scanf("%d: ",&type);
		getline(cin,temp);
		cout << type << ": " << temp << endl;
		switch(type){
			case 1: query(title,temp);break;
			case 2: query(author,temp);break;
			case 3: query(keywords,temp);break;
			case 4: query(publisher,temp);break;
			case 5: query(year,temp);break;
		}
	}
	return 0;
}