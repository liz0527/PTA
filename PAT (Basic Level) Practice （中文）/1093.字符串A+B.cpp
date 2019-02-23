#include <iostream>
#include <string>
using namespace std;
int main(){
  string a,b;
  getline(cin,a);
  getline(cin,b);
  string s = a+b;
  string del="";
  for(int i=0;i<s.length();i++){
    if(del.find(s[i])==string::npos){
      cout << s[i];
      del += s[i];
    }
  }
  return 0;
}