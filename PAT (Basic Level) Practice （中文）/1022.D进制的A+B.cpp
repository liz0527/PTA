#include <iostream>
using namespace std;
int main(){
  int a,b,d,t,s[100];
  int i=0;
  cin >> a >> b >> d;
  t = a + b;
  if(t==0){
    cout << 0;
    return 0;
  }
  while(t){
    s[i] = t%d;
    t = t/d;
    i++;
  }
  for(int j=i-1;j>=0;j--){
    cout << s[j];
  }
  return 0;
}
