#include <iostream>
#include <vector>
#include <functional>//sort()中降序升序函数  可以用cmp自定义代替
#include<algorithm>//sort() 排序
#include <string>//int = stoi(string)  string = to_string(int)  string.push_back(char) string.append(string)
#include <cmath>//sqrt() 平方根  note:结果为浮点数
#include <iomanip>//setprecision()保留浮点数 小数位
#include<cstring>//memcpy(b,a,sizeof(a)) 数组赋值 a->b
#include <set>
using namespace std;
void solve_1023() {
    /*
    0-9数字若干 排序使数最小  0不能作首位
    1.升序排序
    2.把除0外最小的一个数 拿出作为首位
    */
   
    int flag=1, a[10] = {0};
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
        if (a[i] != 0 && i != 0 && flag) {
            cout <<i;
            --a[i];
            flag = 0;
        }
            
    }
    for (int i = 0; i < 10; ++i) {
        while (a[i] != 0) {
            cout << i;
            --a[i];
        }
    }
    cout << endl;
}
int main()
{       
    solve_1023();

    return 0;
}
