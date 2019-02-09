#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> num(n);
  for(int i=0;i<n;i++){
    cin >> num[i];
  }
  m = m%n;
  if(m!=0){
    reverse(begin(num),begin(num)+n);
    reverse(begin(num),begin(num)+m);
    reverse(begin(num)+m,begin(num)+n);
  }
  for(int i=0;i<n-1;i++){
    cout << num[i] << " ";
  }
  cout << num[n-1];
  return 0;
}

/*
#include <iostream>
using namespace std;
int main(){
  int n,m;
  int flag=0;
  cin >> n >> m;
  m = m%n;
  int num[n+m];
  for(int i=m;i<n+m;i++){
    cin >> num[i];
  }
  for(int i=0;i<m;i++){
    num[i] = num[i+n];
  }
  for(int i=0;i<n;i++){
    if(flag==1) cout << " ";
    cout << num[i];
    flag=1;
  }
  return 0;
}
*/