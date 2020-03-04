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
void solve_1022() {
    /*
     A+B 以D(1<d<=10)进制形式输出
     测试点3 sum=0的情况
    */
    int a = 0, b = 0;
    long long sum_10 = 0;
    int d;
    cin >> a >> b >> d;
    sum_10 = a + b;
    string sum_10_str = to_string(sum_10);
    if (d == 10)
        cout << sum_10_str << endl;
    else {
        if (sum_10 == 0)
            cout << "0" << endl;
        else {
            vector<int> result;
            int rest;
            while (sum_10 != 0) {
                rest = sum_10 % d;
                result.push_back(rest);
                sum_10 /= d;
            }
            int size = result.size();
            for (int i = size - 1; i >= 0; --i) {
                cout << result[i];
            }
            cout << endl;
        }
       
    }
  


}
int main()
{       
    solve_1022();

    return 0;
}
