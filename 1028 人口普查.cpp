#include <iostream>
#include <vector>
#include <functional>//sort()中降序升序函数  可以用cmp自定义代替
#include<algorithm>//sort() 排序
#include <string>//int = stoi(string)  string = to_string(int)  string.push_back(char) string.append(string)
#include <cmath>//sqrt() 平方根  note:结果为浮点数  round() 四舍五入
#include <iomanip>//setprecision()保留浮点数 小数位
#include<cstring>//memcpy(b,a,sizeof(a)) 数组赋值 a->b
#include <set>
using namespace std;
struct Birth28 {
    string name;
    string birth;
};
void solve_1028() {
    /*
    1.年龄<=200
    2.
    */
    string name, birthPre;
    string maxName, minName;
    int maxBirth = 0,minBirth=99999999,lBirth=18140906,rBirth=20140906;
    int n,cnt=0;
    cin >> n;
    //vector<Birth28> births;
    int size = 0;
    for (int i = 0; i < n; ++i) {
        //Birth28 info;
        string birthAfter;
        cin >> name >> birthPre;
        size = birthPre.size();
        for (int i = 0; i < size; ++i) {
            if (birthPre[i] != '/')
                birthAfter.push_back(birthPre[i]);
        }
        int birthInt = stoi(birthAfter);
        if (birthInt >= lBirth && birthInt <= rBirth) {//合理日期
            ++cnt;
            if (birthInt > maxBirth) {
                maxBirth = birthInt;
                maxName = name;
            }
            if (birthInt < minBirth) {
                minBirth = birthInt;
                minName = name;
            }
        }
    }
     //数字最小 年龄最大
    if(cnt!=0)
        cout << cnt << " " << minName << " " << maxName << endl;
    else
        cout << "0"<<endl;
}
int main()
{       
    solve_1028();
    return 0;
}
