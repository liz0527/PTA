#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  int word[n+1];
  for(int i=1;i<=n;i++){
    cin >> word[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      vector<int> lie;
      int person[n+1];
      for(int i=1;i<=n;i++){
      	person[i]=1;
      }
      person[i]=person[j]=-1;
      for(int k=1;k<=n;k++){
        if(person[abs(word[k])]*word[k]<0){
          lie.push_back(k);
        }
      }
      if(lie.size()==2 && person[lie[0]]+person[lie[1]]==0){
        cout << i << " " << j;
        return 0;
      }
    }
  }
  cout << "No Solution";
  return 0;
}