#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    int temp,average=0,tea;
    vector<int> v;
    cin >> tea;
    for(int j=0;j<n-1;j++){
      cin >> temp;
      if(temp>=0 && temp <=m){
        v.push_back(temp);
        average += temp;
      }
    }
    sort(v.begin(),v.end());
    average = average-v[0]-(v[v.size()-1]);
    average = average*1.0/(v.size()-2);
    average = int((average+tea+1)/2);
    cout << average << endl;
  }
  return 0;
}
