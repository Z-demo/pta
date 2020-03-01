#include <iostream>
#include <vector>
#include <functional>//sort()中降序升序函数  可以用cmp自定义代替
#include<algorithm>//sort() 排序
#include <string>//int = stoi(string)  string = to_string(int)  string.push_back(char) string.append(string)
#include <cmath>//sqrt() 平方根  note:结果为浮点数
#include <iomanip>//setprecision()保留浮点数 小数位
#include <set>
using namespace std;

void solve_1016() {
    string A, B,Pa,Pb;
    char Da, Db;
    cin >> A >> Da >> B >> Db;
    int asize = A.size(),bsize=B.size();

    for (int i = 0; i < asize; ++i) {
        if (A[i] == Da)
            Pa.push_back(Da);
    }
    for (int i = 0; i < bsize; ++i) {
        if (B[i] == Db)
            Pb.push_back(Db);
    }
    int sum =( Pa == "" ? 0 : stoi(Pa)) +( Pb == "" ? 0 : stoi(Pb));
    cout << sum << endl;
}

int main()
{       
    solve_1016();
    return 0;
}
