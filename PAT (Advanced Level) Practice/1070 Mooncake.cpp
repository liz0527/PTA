#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct goods{
	double w;
	double p;
	double val;
};
bool cmp(goods a, goods b){
	return a.val > b.val;
}
int main(){
	int n,d;
	cin >> n >> d;
	double weight=0.0;
	double price=0.0;
	goods cake[n];
	for(int i=0;i<n;i++){
		cin >> cake[i].w;
	}
	for(int i=0;i<n;i++){
		cin >> cake[i].p;
		cake[i].val = cake[i].p/cake[i].w;
	}
	sort(cake,cake+n,cmp);
	for(int i=0;i<n;i++){
		if(weight+cake[i].w<=d){
			weight += cake[i].w;
			price += cake[i].p;
		}
		else {
			price += (d-weight)*cake[i].val;
			break;
		}
	}
	printf("%.2f\n",price);
	return 0;
}