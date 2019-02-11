#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
/*结构体*/
struct person {
  int win;
  int same;
  int lose;
};
/*判断输赢*/
int game(char a, char b){
  if((a=='C'&&b=='J')||(a=='J'&&b=='B')||(a=='B'&&b=='C')){return 1;}
  else if(a==b){return 0;}
  else {return -1;}
}
/*获胜手势*/
void most(map<char,int>m,char b,char c,char j){
  if(m[b]>=m[c] && m[b]>=m[j]){
    cout << "B";
  }
  else if(m[c]>m[b]&&m[c]>=m[j]){
    cout << "C";
  }
  else cout << "J";
}
int main(){
  int n;
  cin >> n;
  person a;
  char bb='B',cc='C',jj='J';
  a.win=a.same=a.lose=0;
  map<char,int> ma,mb;//记录获胜最多手势
  for(int i=0;i<n;i++){
    char ax,bx;
    cin >> ax >> bx;
    int x = game(ax,bx);
    if(x==1){//甲胜
      a.win++;
      ma[ax]++;
    }
    else if(x==-1){//甲输
      a.lose++;
      mb[bx]++;
    }
    else {
      a.same++;
    }
  }
  cout << a.win << " " << a.same << " " << a.lose << endl;
  cout << a.lose << " " << a.same << " " << a.win << endl;
  most(ma,bb,cc,jj);
  cout << " ";
  most(mb,bb,cc,jj);
  return 0;
}