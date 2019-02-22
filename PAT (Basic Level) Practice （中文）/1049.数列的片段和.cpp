#include <iostream>
using namespace std;
int main(){
  int n;
  cin >> n;
  double temp,count=0.0;
  for(int i=1;i<=n;i++){
    cin >> temp;
    count += temp*i*(n-i+1);
  }
  printf("%.2f",count);
  return 0;
}