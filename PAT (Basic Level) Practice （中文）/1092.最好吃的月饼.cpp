#include <iostream>
#include <algorithm>
using namespace std;
struct cake {
  int num;
  int sell=0;
};
int cmp(cake a,cake b){
  if(a.sell != b.sell){
    return a.sell > b.sell;
  }
  else {
    return a.num < b.num;
  }
}
int main(){
  int n,m;
  cin >> n >> m;
  cake cakes[n];
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      int temp;
      cin >> temp;
      cakes[j].num = j+1;
      cakes[j].sell += temp;
    }
  }
  sort(cakes,cakes+n,cmp);
  int best = cakes[0].sell,k=0;
  cout << best << endl;
  while(best == cakes[k].sell){
    if(k!=0) cout << " ";
    cout << cakes[k].num;
    k++;
  }
  return 0;
}