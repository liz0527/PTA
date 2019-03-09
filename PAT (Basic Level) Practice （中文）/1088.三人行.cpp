#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
void compare(int m, double n){
  if(m>n) cout << " Gai";
  else if(m<n) cout << " Cong";
  else if(m==n) cout << " Ping";
}
int main(){
  int m,x,y,a,b;
  double c=-1.0;
  cin >> m >> x >> y;
  for(a=99;a>9;a--){
  	b = 10*(a%10)+a/10;
  	if(b*1.0/y == abs(a-b)*1.0/x){
  		c = b*1.0/y;
  		cout << a;
		compare(m,a);compare(m,b);compare(m,c);
  		return 0;
  	}
  }
  cout << "No Solution";
  return 0;
}