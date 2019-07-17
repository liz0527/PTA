#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int ga,sa,ka,gb,sb,kb;
	int galleon,sickle,knut;
	scanf("%d.%d.%d",&ga,&sa,&ka);
	scanf("%d.%d.%d",&gb,&sb,&kb);
	knut = (ka+kb)%29;
	sickle = ((ka+kb)/29 + sa+sb)%17;
	galleon = ((ka+kb)/29 + sa+sb)/17 + (ga+gb);
	printf("%d.%d.%d",galleon,sickle,knut);
	return 0;
}
/*
	注意计算进位时的被除数不是单纯的a+b，还要加上之前的进位
*/