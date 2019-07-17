#include <iostream>
using namespace std;
int main(){
	char word[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	int rgb[3][2]={};
	int temp;
	for(int i=0;i<3;i++){
		int cnt=0;
		cin >> temp;
		do{
			rgb[i][cnt++] = temp%13;
			temp /= 13;
		}while(temp!=0);
	}
	cout << "#";
	for(int i=0;i<3;i++){
		cout << word[rgb[i][1]] << word[rgb[i][0]];
	}
	return 0;
}