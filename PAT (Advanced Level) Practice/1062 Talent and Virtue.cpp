#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Student{
	string id;
	int virtue;
	int talent;
};
bool cmp(Student a,Student b){
	if(a.virtue+a.talent==b.virtue+b.talent){
		if(a.virtue==b.virtue) return strcmp(b.id.c_str(),a.id.c_str())>0;
		return a.virtue > b.virtue;
	}
	return a.virtue+a.talent > b.virtue+b.talent;
}
int main(){
	int n,l,h;
	cin >> n >> l >> h;
	vector<Student> sages,noble,fool,stu;
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0,t_virtue,t_talent;
	string t_id;
	for(int i=0;i<n;i++){
		cin >> t_id >> t_virtue >> t_talent;
		if(t_talent>=h && t_virtue>=h){
			sages[cnt1].id = t_id;
			sages[cnt1].virtue = t_virtue;
			sages[cnt1].talent = t_talent;
			cnt1++;
		}else if(t_talent<h && t_talent>=l && t_virtue>=h){
			noble[cnt2].id = t_id;
			noble[cnt2].virtue = t_virtue;
			noble[cnt2].talent = t_talent;
			cnt2++;
		}else if(t_talent<h && t_talent>=l && t_virtue<h &&t_talent>=l && t_virtue>=t_talent){
			fool[cnt3].id = t_id;
			fool[cnt3].virtue = t_virtue;
			fool[cnt3].talent = t_talent;
			cnt3++;
		}else if(t_talent>=l && t_virtue>=l){
			stu[cnt4].id = t_id;
			stu[cnt4].virtue = t_virtue;
			stu[cnt4].talent = t_talent;
			cnt4++;
		}
	}
	sort(sages,sages+cnt1,cmp);
	sort(noble,noble+cnt2,cmp);
	sort(fool,fool+cnt3,cmp);
	sort(stu,stu+cnt4,cmp);
	cout << cnt1+cnt2+cnt3+cnt4 << endl;
	for(int i=0;i<cnt1;i++) 
		cout << sages[i].id << " " << sages[i].virtue << " " << sages[i].talent <<endl;
	for(int i=0;i<cnt2;i++)
		cout << noble[i].id << " " << noble[i].virtue << " " << noble[i].talent <<endl;
	for(int i=0;i<cnt3;i++)
		cout << fool[i].id << " " << fool[i].virtue << " " << fool[i].talent <<endl;
	for(int i=0;i<cnt4;i++)
		cout << stu[i].id << " " << stu[i].virtue << " " << stu[i].talent <<endl;
	return 0;
}