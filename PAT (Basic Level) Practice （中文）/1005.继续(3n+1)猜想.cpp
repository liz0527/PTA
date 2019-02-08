#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {return a > b;}
int main(){
  int n;
  int flag=0;
  vector<int> a;
  vector<int> num;
  cin >> n;
  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    a.push_back(m);
    while(m!=1){
      /*当n为奇数，就令n = 3*n+1，之后将其砍掉一半。*/
      if(m%2!=0) m=3*m+1;
      m=m/2;
      num.push_back(m);
    }
  }
  sort(a.begin(),a.end(),cmp);
  for(int i=0;i<n;i++){
    for(int j=0;j<num.size();j++){
      if(a[i]==num[j]) {
        a[i]=0;
        break;
      }
    }
    if(a[i]!=0){
      /*flag保证只有第一次输出的数前面没有空格。*/
      if(flag==1) cout << " ";
      cout << a[i];
      flag=1;
    }
  }
  return 0;
  
}