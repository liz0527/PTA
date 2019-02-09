#include <iostream>
#include <stack>
using namespace std;
int main(){
  string s;
  stack<string> str;
  while(cin >> s) str.push(s);
  cout << str.top();
  str.pop();
  while(!str.empty()){
    cout << " " << str.top();
    str.pop();
  }
  return 0;
}