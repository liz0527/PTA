#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  int num[n];
  for(int i=0;i<n;i++){
    cin >> num[i];
  }
  sort(num,num+n);
  int len = num[0];
  for(int i=1;i<n;i++){
    len = (len+num[i])/2;
  }
  cout << len;
  return 0;
}