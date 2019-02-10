#include <iostream>
#include <string>
using namespace std;
int main(){
  string s1,s2,s3,s4;
  cin >> s1 >> s2 >> s3 >> s4;
  int flag=1;//星期和小时的标志
  string wek[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
  for(int i=0;i<s1.length()&&i<s2.length();i++){
    if(flag==1 && s1[i]==s2[i] && s1[i]>='A' && s1[i]<='G'){
      cout << wek[s1[i]-'A'] << " ";
      flag=2;
      i++;
    }
    if(flag==2 && s1[i]==s2[i] && ((s1[i]>='A'&&s1[i]<='N')||(s1[i]>='0'&&s1[i]<='9'))){
      if(s1[i]<'A'){
        cout << '0' << s1[i] << ":";
      }
      else {
        cout << s1[i]-'A'+10 << ":";
      }
      break;
    }
  }
  for(int i=0;i<s3.length()&& i<s4.length();i++){
    if(s3[i]==s4[i] && ((s3[i]>='a'&&s3[i]<='z')||(s3[i]>='A'&&s3[i]<='Z'))){
      if(i<10){
        cout << "0";
      }
      cout << i;
      break;
    }
  }
  return 0;
}