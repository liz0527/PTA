#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	string s;
	int k;
	vector<string> hand,eye,mouse;
	for(int i=0;i<3;i++){
		getline(cin,s);
		string temp="";
		for(int j=0;j<s.length();j++){
			if(s[j]=='['){
				temp = "";
			}
			else if(s[j]==']'){
				if(i==0) hand.push_back(temp);
				else if(i==1) eye.push_back(temp);
				else if(i==2) mouse.push_back(temp);
			}
			else temp += s[j];
		}
	} 
	cin >> k;
	int lhand,leye,m,reye,rhand;
	for(int i=0;i<k;i++){
		cin >> lhand >> leye >> m >> reye >> rhand;
		if(lhand>0 && leye>0 && m>0 && reye>0 && rhand>0 && lhand<=hand.size() && leye<=eye.size() && m<=mouse.size() && rhand<=hand.size() && reye<=eye.size()){
			cout << hand[lhand-1] << "(" << eye[leye-1] << mouse[m-1] << eye[reye-1] << ")" << hand[rhand-1] << endl;
		}
		else cout << "Are you kidding me? @\\/@" << endl;
	}
	return 0;
}