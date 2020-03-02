#include <iostream>
#include <vector>
#include <functional>//sort()中降序升序函数  可以用cmp自定义代替
#include<algorithm>//sort() 排序
#include <string>//int = stoi(string)  string = to_string(int)  string.push_back(char) string.append(string)
#include <cmath>//sqrt() 平方根  note:结果为浮点数
#include <iomanip>//setprecision()保留浮点数 小数位
#include <set>
using namespace std;

void solve_1017() {
        string A;
        int B;
        int result = 0, rest = 0;
        cin >> A >> B;
        for (int i = 0; i < A.size(); i++) {
            result = (rest * 10 + A[i] - '0') / B;
            rest = (rest * 10 + A[i] - '0') % B;
            if (i != 0 || A[i] - '0' > B || A.size() == 1)//A.size()==1，测试点2 
                cout << result;
        }
        cout << " " << rest;

}
int main()
{       
    solve_1017();
    return 0;
}
