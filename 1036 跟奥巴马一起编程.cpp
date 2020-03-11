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
void solve_1036() {
    int n;
    char c;
    cin >> n >> c;
    //int row = n / 2 + n % 2;//两种方式都可以
    int row = round((double)n / 2);
    for (int i = 0; i < n; ++i) cout << c;
    cout << endl;
    for (int i = 0; i < row-2; ++i) {
        cout << c;
        for (int i = 0; i < n - 2; ++i) cout << " ";
        cout << c << endl;
    }
    
    for (int i = 0; i < n; ++i) cout << c;
    cout << endl;
}

int main()
{       
   solve_1036();
    return 0;
}
