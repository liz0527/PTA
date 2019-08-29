#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n;
  long long int p;
  cin >> n >> p;
  int num[n];
  int temp=0,result=0;
  for(int i=0;i<n;i++){
    cin >> num[i];
  }
  sort(num,num+n);
  for(int i=0;i<n;i++){
    for(int j=i+result;j<n;j++){
      if(num[j]<=num[i]*p){
        temp = j-i+1;
        if(temp>result) result = temp;
      }
      else {
        break;
      }
    }
  }
  cout << result;
  return 0;
}