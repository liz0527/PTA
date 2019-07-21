#include <iostream>
#include <string>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  if(a+b<0) cout << "-";
  string s = to_string(abs(a+b));
  for(int i=0;i<s.length()%3;i++){
    cout << s[i];
  }
  for(int i=s.length()%3;i<s.length();i+=3){
    if(i!=0) cout << ",";
    cout << s[i] << s[i+1] << s[i+2];
  }
  return 0;
}