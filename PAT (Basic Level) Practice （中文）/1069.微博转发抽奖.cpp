#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
  int m,n,s,flag=0;
  cin >> m >> n >> s;
  map<string,int> get;
  string str;
  for(int i=1;i<=m;i++){
    cin >>str;
    if(get[str]==1) s=s+1;
    if(i==s && get[str]==0){
      cout << str << endl;
      get[str]=1;
      s=s+n;
      flag=1;
    }
  }
  if(flag==0) cout << "Keep going...";
  return 0;
}