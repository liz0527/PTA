#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  cin >> s;
  int i=0;
  while(s[i]!='E') i++;
  string t = s.substr(1,i-1);//E前面的数字
  int n = stoi(s.substr(i+1));//E后面的数字
  if(s[0]=='-') cout << "-";//先输出整体符号
  if(n<0){//小数点要往前移动
    cout << "0.";//先输出小数点
    for(int j=0;j<abs(n)-1;j++){//再输出n-1个0
      cout << "0";
    }
    for(int j=0;j<t.length();j++){//最后把数字部分输出
      if(t[j]!='.') cout << t[j];
    }
  }
  else {//小数点要往后移动
    cout << t[0];
    int cnt,j;
    for(j=2,cnt=0;j<t.length()&&cnt<n;j++,cnt++){//将t尽可能输出n个字符
      cout << t[j];
    }
    if(j==t.length()){//如果t已经输出最后一个字符(j == t.length())那么就在后面补n-cnt个0
      for(int k=0;k<n-cnt;k++){
        cout << "0";
      }
    }
    else {//否则就补充一个小数点，然后继续输出t剩余的没有输出的字符
      cout << ".";
      for(int k=j;k<t.length();k++){
        cout << t[k];
      }
    }
  }
  return 0;
}