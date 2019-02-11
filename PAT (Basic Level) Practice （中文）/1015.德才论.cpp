#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct student{
  int number;
  int de;
  int cai;
};
bool cmp(student a,student b){
  if((a.de+a.cai)!=(b.de+b.cai)){
    return (a.de+a.cai) > (b.de+b.cai);
  }
  else if(a.de != b.de){
    return a.de > b.de;
  }
  else return a.number < b.number;
}
int main(){
  int n,l,h;
  scanf("%d %d %d",&n,&l,&h);
  student stu;
  vector<student> v[4];
  int total=n;
  for(int i=0;i<n;i++){
    scanf("%d %d %d",&stu.number,&stu.de,&stu.cai);
    if(stu.de<l || stu.cai<l){//不及格
      total--;
    }
    else if(stu.de >=h && stu.cai>=h){//第一类
      v[0].push_back(stu);
    }
    else if(stu.de>=h && stu.cai<h){//第二类
      v[1].push_back(stu);
    }
    else if(stu.de<h && stu.de>=stu.cai){//第三类
      v[2].push_back(stu);
    }
    else {//第四类
      v[3].push_back(stu);
    }
  }
  printf("%d\n",total);
  for(int i=0;i<4;i++){
    sort(v[i].begin(),v[i].end(),cmp);
    for(int j=0;j<v[i].size();j++){
      printf("%d %d %d\n",v[i][j].number,v[i][j].de,v[i][j].cai);
    }
  }
  return 0;
}