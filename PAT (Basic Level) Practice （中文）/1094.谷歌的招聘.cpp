#include <iostream>
#include <string>
using namespace std;
bool isPrime(int n){
  if(n==0 || n==1) return false;
  for(int i=2;i*i<=n;i++){
    if(n%i==0) return false;
  }
  return true;
}
int main(){
  int l,k;
  string s;
  cin >> l >> k;
  cin >> s;
  for(int i=0;i<=l-k;i++){
  	string str = s.substr(i,k);
    int temp = stoi(str);
    if(isPrime(temp)){
      cout << str;
      return 0;
    }
  }
  cout << "404\n";
  return 0;
}