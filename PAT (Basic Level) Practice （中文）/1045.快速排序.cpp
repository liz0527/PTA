#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n,max=0,cnt=0;
  int v[100000];
  scanf("%d",&n);
  vector<int> a(n),b(n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    b[i] = a[i];
  }
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
    if(b[i]==a[i] && b[i]>max){
      v[cnt++] = b[i];
    }
    if(b[i] > max){
       max = b[i];
    }
  }
  printf("%d\n",cnt);
  for(int i=0;i<cnt;i++){
    if(i!=0) printf(" ");
    printf("%d",v[i]);
  }
  printf("\n");
  return 0;
}