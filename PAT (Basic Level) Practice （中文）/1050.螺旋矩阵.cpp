#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmp(int a,int b){
  return a>b;
}
int main(){
  int N,m,n,t=0;
  cin >> N;
  int num[N];
  for(int i=0;i<N;i++){
    cin >> num[i];
  }
  sort(num,num+N,cmp);
  for(n = sqrt(N);n>=1;n--){
    if(N%n==0){
        m = N/n;
        break;
    }
  }
  int squre[m][n];
  for(int i=0;i<(m+1)/2;i++){
    for (int j = i; j <= n - 1 - i && t <= N - 1; j++)                
      squre[i][j] = num[t++];        
    for (int j = i + 1; j <= m - 2 - i && t <= N - 1; j++)
      squre[j][n - 1 - i] = num[t++];        
    for (int j = n - i - 1; j >= i && t <= N - 1; j--)                
      squre[m - 1 - i][j] = num[t++];        
    for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; j--)                
      squre[j][i] = num[t++]; 
  }
  for(int i=0;i<m;i++){
    if(i!=0) cout << endl;
    for(int j=0;j<n;j++){
      if(j!=0) cout << " ";
      cout << squre[i][j];
    }
  }
  return 0;
}