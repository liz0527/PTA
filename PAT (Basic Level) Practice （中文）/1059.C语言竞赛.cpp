#include <iostream>
#include <string>
using namespace std;
struct student {
  int number;
  string award;
  int flag=0;
};
bool isPrimer(int a){
  for(int i=2;i*i<=a;i++){
    if(a%i==0) return 0;
  }
  return 1;
}
int main(){
  int n,k;
  int temp;
  scanf("%d",&n);
  student stu[n+1];
  //输入
  for(int i=1;i<=n;i++){
    scanf("%d",&stu[i].number);
    if(i==1) stu[i].award = "Mystery Award";
    else if(isPrimer(i)){
      stu[i].award = "Minion";
    }
    else stu[i].award = "Chocolate";
  }
  //查询
  scanf("%d",&k);
  for(int i=0;i<k;i++){
    scanf("%d",&temp);
    printf("%04d: ",temp);
    int j;
    for(j=1;j<=n;j++){
      if(stu[j].number == temp){
        if(stu[j].flag==1){printf("Checked\n");}
        else {printf("%s\n",stu[j].award.c_str());stu[j].flag=1;}
        break;
      }
    }
    if(j==n+1) printf("Are you kidding?\n");
  }
  return 0;
}