#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Student{
	string number;
	int score;
	int local_rank;
	int location_num;
}; 
bool cmp(Student a, Student b){
	if(a.score != b.score) return a.score>b.score;
	else return a.number<b.number;
}
int main(){
	int count=0;
	int n,k,score;
	string num;
	Student stu[30001];
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=0;j<k;j++){
			cin >> stu[count].number >> stu[count].score;
			stu[count].location_num = i;
			count++;
		}
		sort(stu+count-k,stu+count,cmp);
		stu[count-k].local_rank = 1;
		for(int j=count-k+1;j<count;j++){
			if(stu[j].score!=stu[j-1].score)
				stu[j].local_rank = j+1-(count-k);
			else
				stu[j].local_rank = stu[j-1].local_rank;
		}
	}
	sort(stu,stu+count,cmp);
	cout << count << endl;
	int rank = 1;
	for(int i=0;i<count;i++){
		if(i>0 && stu[i].score!=stu[i-1].score)
			rank = i + 1;
		cout << stu[i].number << " " << rank << " " << stu[i].location_num << " " << stu[i].local_rank << endl;
	}
	return 0;
}