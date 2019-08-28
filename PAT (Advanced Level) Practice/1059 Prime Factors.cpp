#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 100010;
bool isPrime(int n){
	if(n<=1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int prime[maxn],pNum=0;
bool p[maxn]={false};
void findPrime(){
	for(int i=2;i<maxn;i++){
		if(p[i]==false){
			prime[pNum++]=i;
			for(int j=i+i;j<maxn;j+=i){
				p[j]=true;
			}
		}
	}
}
struct factor{
	int x,cnt;
}fac[10];
int main(){
	long long n;
	cin >> n;
	if(n==1) {
		cout << "1=1";
		return 0;
	}
	findPrime();
	int num=0;
	cout << n << "=";
	for(int i=0;i<pNum && prime[i]<=sqrt(n);i++){
		if(n%prime[i]==0){
			fac[num].x=prime[i];
			fac[num].cnt=0;
			while(n%prime[i]==0){
				n /= prime[i];
				fac[num].cnt++;
			}
			num++;
		}
	}
	if(n!=1){
		fac[num].x=n;
		fac[num].cnt=1;
		num++;
	}
	for(int i=0;i<num;i++){
		if(i!=0) cout << "*";
		cout << fac[i].x;
		if(fac[i].cnt!=1)  cout << "^" << fac[i].cnt;
	}
	return 0;
}