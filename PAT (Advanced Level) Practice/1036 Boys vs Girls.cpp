#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
struct Student{
	string name;
	char gender;
	string id;
	int grade;
};
int main(){
	int n;
	int high=0,low=100;
	int high_num=-1,low_num=-1;
	cin >> n;
	Student stu[n];
	for(int i=0;i<n;i++){
		cin >> stu[i].name >> stu[i].gender >> stu[i].id >>stu[i].grade;
		if(stu[i].gender=='F' && stu[i].grade>=high){
			high = stu[i].grade;
			high_num = i;
		}
		if(stu[i].gender=='M' && stu[i].grade<=low){
			low = stu[i].grade;
			low_num = i;
		}
	}
	if(high_num!=-1) cout << stu[high_num].name << " " << stu[high_num].id << endl;
	else cout << "Absent" << endl;
	if(low_num!=-1) cout << stu[low_num].name << " " << stu[low_num].id << endl;
	else cout << "Absent" << endl;
	if(high_num!=-1 && low_num!=-1) cout << stu[high_num].grade - stu[low_num].grade << endl;
	else cout << "NA" << endl;
	return 0;
}