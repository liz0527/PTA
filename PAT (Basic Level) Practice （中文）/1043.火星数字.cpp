#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
string a[13]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13]={"####", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
void func1(int t){//地球文转火星文，就是10进制转13进制
  if(t/13) cout << b[t/13];
  if((t/13)&&(t%13)) cout << " ";
  if(t%13||t==0) cout << a[t%13];
}
void func2(){//火星文转地球文
  int t1=0,t2=0;
  string s1 = s.substr(0,3),s2;
  if(s.length()>4) s2=s.substr(4,3);
  for(int j=1;j<=12;j++){
    if(s1==a[j]||s2==a[j]) t2=j;
    if(s1==b[j]) t1=j;
  }
  cout << t1*13+t2;
}
int main(){
  int n;
  cin >> n;
  getchar();
  for(int i=0;i<n;i++){
    getline(cin,s);
    if(s[0]>='0'&&s[0]<='9'){
      func1(stoi(s));
    }
    else func2();
    cout << endl;
  }
  return 0;
}
