#include <iostream>
#include <map>
using namespace std;
int main(){
  int m,n,TOL,x,y,cnt=0;
  map<int,int> mapp;
  cin >> m >> n >> TOL;
  int num[n+2][m+2]={0};
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> num[i][j];
      mapp[num[i][j]]++;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      int flag=0;
      if(i>0 && i<=n && j>0 && j<=m){
        if(abs(num[i][j]-num[i-1][j-1])>TOL && abs(num[i][j]-num[i-1][j])>TOL && abs(num[i][j]-num[i-1][j+1])>TOL && abs(num[i][j]-num[i][j-1])>TOL && abs(num[i][j]-num[i][j+1])>TOL && abs(num[i][j]-num[i+1][j-1])>TOL && abs(num[i][j]-num[i+1][j])>TOL && abs(num[i][j]-num[i+1][j+1])>TOL){
          flag=1;
        }
      }
      if(flag==1 && mapp[num[i][j]]==1) {
      	x=i;y=j;cnt++;
      }
    }
  }
  if(cnt==0) cout << "Not Exist";
  else if(cnt==1) cout << "(" << y << ", " << x << "): " << num[x][y];
  else cout << "Not Unique";
  return 0;
}