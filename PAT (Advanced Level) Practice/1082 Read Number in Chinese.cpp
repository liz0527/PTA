#include <iostream>
#include <string>
#include <vector>
using namespace std;
string num[10] = { "ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string c[6] = { "Ge","Shi", "Bai", "Qian", "Yi", "Wan" };
int J[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
vector<string> res;
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "ling";
        return 0;
    }
    if (n < 0) {
        cout << "Fu ";
        n = -n;
    }
    int part[3];
    part[0]= n / 100000000; 
    part[1]= (n % 100000000) / 10000;
    part[2] = n % 10000;
    bool zero = false; //是否在非零数字前输出合适的ling
    int printCnt = 0; //用于维护单词前没有空格，之后输入的单词都在前面加一个空格。
    for (int i = 0; i < 3; i++) {
        int temp = part[i]; //三个部分，每部分内部的命名规则都一样，都是X千X百X十X
        for (int j = 3; j >= 0; j--) {
            int curPos = 8 - i * 4 + j; //当前数字的位置
            if (curPos >= 9) continue; //最多九位数
            int cur = (temp / J[j]) % 10;//取出当前数字
            if (cur != 0) {
                if (zero) {
                    printCnt++ == 0 ? cout<<"ling" : cout<<" ling";
                    zero = false;
                }
                if (j == 0)
                    printCnt++ == 0 ? cout << num[cur] : cout << ' ' << num[cur]; //在个位，直接输出
                else                             
                    printCnt++ == 0 ? cout << num[cur] << ' ' << c[j] : cout << ' ' << num[cur] << ' ' << c[j]; //在其他位，还要输出十百千
            } else {
                if (!zero&&j != 0 && n / J[curPos] >= 10) zero = true;   //注意100020这样的情况
            }
        }
        if (i != 2 && part[i]>0) cout << ' ' << c[i + 4]; //处理完每部分之后，最后输出单位，Yi/Wan
    }
    return 0;
}

/*
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	string unit[9]={"","Shi ","Bai ","Qian ","Wan ","Shi ","Bai ","Qian ","Yi "};
	string num[10]={"ling ","yi ","er ","san ","si ","wu ","liu ","qi ","ba ","jiu "};
	string input,res="";
	int zero=0;
	cin >> input;
	if(input[0]=='-') {
		res += "Fu ";
		input = input.substr(1);
	}
	int len = input.length();
	for(int i=0;i<len/2;i++){
		char temp = input[i];
		input[i] = input[len-i-1];
		input[len-i-1] = temp;
	}
	for(int i=len-1;i>=0;i--){
		if(input[i]=='0'){
			zero = 1;
			if(unit[i]=="Wan ") res += unit[i];
		}else{
			if(zero==1){
				res += "ling ";
				zero = 0;
			}
			res = res + num[input[i]-'0'] + unit[i];
		}
	}
	res = res.substr(0,res.length()-1);
	if(res.substr(res.length()-4)=="ling") res = res.substr(0,res.length()-5);
	cout << res; 
	return 0;
}
*/