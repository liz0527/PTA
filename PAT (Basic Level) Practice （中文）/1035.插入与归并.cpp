#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n,a[100],b[100],i,j;
  cin >> n;
  for(int k=0;k<n;k++){
    cin >> a[k];
  }
  for(int k=0;k<n;k++){
    cin >> b[k];
  }
  for(i=0;i<n-1 && b[i]<=b[i+1];i++);//令i指向中间序列中满足从左到右是从小到大顺序的最后一个下标
  for(j=i+1;j<n && a[j]==b[j];j++);//j指向从i+1开始，第一个不满足a[j] == b[j]的下标
  if(j==n){//如果j顺利到达下标n，说明是插入排序，再下一次的序列是sort(a, a+i+2);
    cout << "Insertion Sort" << endl;
    sort(a,a+i+2);
  }
  else {
    cout << "Merge Sort" << endl;
    int k=1,flag=1;
    while(flag){
      flag=0;
      for(i=0;i<n;i++){
        if(a[i]!=b[i]){
          flag=1;
        }
      }
      k=k*2;
      for(i=0;i<n/k;i++){
        sort(a+i*k,a+(i+1)*k);
      }
      sort(a+n/k*k,a+n);
    }
  }
  for (j = 0; j < n; j++) {
    if (j != 0) printf(" ");
    printf("%d", a[j]);
  }    
  return 0; 
}