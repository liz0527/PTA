#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin >> s;
  int countt=0,countp=0,result=0,len=s.length();
  for(int i=0;i<len;i++){
    if(s[i]=='T') countt++;
  }
  for(int i=0;i<len;i++){
    if(s[i]=='P') countp++;
    else if(s[i]=='T') countt--;
    else if(s[i]=='A') result = (result + (countp*countt)%1000000007)%1000000007;
  }
  cout << result;
  return 0;
}