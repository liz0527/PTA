#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
  return a > b;
}
int main(){
  int n;
  cin >> n;
  int m[n+1];
  for(int i=1;i<=n;i++){
    cin >> m[i];
  }
  sort(m+1,m+n+1,cmp);
  int ans=0,p=1;
  while(ans<=n && m[p]>p){
    ans++;
    p++;
  }
  cout << ans;
  return 0;
}