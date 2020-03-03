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
void solve_1021(){
    int a[10] = {0,0,0,0,0,0,0,0,0,0};
    string data;
    cin >> data;
    int size = data.size();

    for (int i = size - 1; i >=0; --i) {
        int num = data[i] - '0';
        a[num] += 1;
    }
    for (int i = 0; i < 10; ++i) {
        if (a[i] != 0)
            cout << i << ":" << a[i] << endl;
    }
}
int main()
{       
    solve_1021();

    return 0;
}
