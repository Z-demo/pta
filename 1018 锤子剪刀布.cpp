#include <iostream>
#include <vector>
#include <functional>//sort()中降序升序函数  可以用cmp自定义代替
#include<algorithm>//sort() 排序
#include <string>//int = stoi(string)  string = to_string(int)  string.push_back(char) string.append(string)
#include <cmath>//sqrt() 平方根  note:结果为浮点数
#include <iomanip>//setprecision()保留浮点数 小数位
#include <set>
using namespace std;
struct Caiquan {
    int s;//胜
    int p;//平
    int f;//负
};
void solve_1018() {
    Caiquan j, y;
    j.s = j.p = j.f = 0;
    y.s = y.p = y.f = 0;
    int C1 = 0, B1 = 0, J1 = 0, C2 = 0, J2 = 0, B2 = 0;
    int n,k;
    cin >> n;
    char a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (a == b) {
            ++j.p;
            ++y.p;
        }
        else if (a == 'C') {
            //b == 'J' ? ++j.s, ++y.f, ++C1 : b=='B'? ++j.f,++y.s,++B2:k++;
            b == 'J' ? (++j.s, ++y.f, ++C1) :  (++j.f, ++y.s, ++B2);
        }
        else if (a == 'J') {
            b == 'B' ? (++j.s, ++y.f ,++J1): (++j.f, ++y.s,++C2);
        }
        else {
            b == 'C' ? (++j.s, ++y.f, ++B1) :(++j.f, ++y.s, ++J2);
        }
    }
    cout << j.s<<" " << j.p <<" "<< j.f << endl;
    cout << y.s <<" "<< y.p <<" "<< y.f << endl;
    char max1,max2;
    B1 >= C1 && B1 >=J1 ? max1 = 'B' : C1 >= B1 && C1 >=J1 ? max1 = 'C' :max1 = 'J';
    B2 >= C2 && B2 >= J2 ? max2 = 'B' :C2 >= B2 && C2 >=J2 ? max2 = 'C' :  max2 = 'J';
    cout << max1 << " " << max2<<endl;
}
int main()
{       
    solve_1018();
    return 0;
}
