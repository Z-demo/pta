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
void solve_1027() {
    /*
    1.每行奇数个打印沙漏 17 = 5 3 1 3 5 
    2.中心对称
    3.相邻行差2
    4.N可能大于所需  m<=N  m尽可能大的组成沙漏
    */
    int n,m,rest=0;//rest = n - m
    char f;
    cin >> n >> f;
    if (n < 1)
        exit(0);
    m = 1;
    int i=3;
    vector<int> printCnt;
    printCnt.push_back(1);
    while (m <= n) {
        if ((m + 2 * i) <= n) {
            m += 2 * i;
            printCnt.push_back(i);
        }
        else {//不能再拓宽两行 m最大
            rest = n - m;
            break;
        }
        i += 2;
    }

    int size = printCnt.size();
    int max= printCnt[size-1];
    for (int i = size - 1; i >= 0; --i) {
        int cnt = printCnt[i];
        int cnt2 = (max - cnt) / 2;
        for (int j = 0; j < cnt2; j++)
            cout << " ";
        for (int j = 0; j < cnt; ++j)
            cout << f;
        cout << endl;
    }
    for (int i = 1; i< size; ++i) {
        int cnt = printCnt[i];
        int cnt2 = (max - cnt) / 2;
        for (int j = 0; j < cnt2; j++)
            cout << " ";
        for (int j = 0; j < cnt; ++j)
            cout << f;
        cout << endl;
    }
    cout << rest << endl;
}
int main()
{       
    solve_1027();
    return 0;
}
