#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  int m;
  cin >> m;
  string k;
  for(int i=0;i<m;i++){
    cin >> k;
    string temp;
    int len=k.length(),j;
    for(j=1;j<10;j++){
      temp = to_string(stoi(k)*stoi(k)*j);
      if(temp.substr(temp.length()-len)==k){
        cout << j << " " << temp << endl;
        break;
      }
    }
    if(j==10) cout << "No" << endl;
  }
  return 0;
}