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
struct Yuebing {
    double kc;
    double zsj;
    double dj;
};
bool cmp1020(Yuebing a,Yuebing b){
    return a.dj > b.dj;
};
void solve_1020() {
    /*
    1.库存 总售价 市场需求
    */
    int n;
    double d;
    cin >> n >> d;
    vector<int> kc;
    double kcSum = 0;
    double zsjSum = 0;
    vector<Yuebing> yb;
    
    double k, s;
    //输出化月饼
    for (int i = 0; i < n; ++i) {
        Yuebing y;
        cin >> k;
        y.kc = k;
        kcSum += k;
        yb.push_back(y);
    }
    for (int i = 0; i < n; ++i) {
        cin >> s;
        yb[i].zsj = s;
        zsjSum += s;
        yb[i].dj = yb[i].zsj / yb[i].kc;
    }
    double rest = d, sjSum = 0;//rest剩余需求 sjSum 售价和
    int i = 0;
    if (d >= kcSum)
        cout << fixed << setprecision(2) << zsjSum << endl;
    else {
        sort(yb.begin(), yb.end(), cmp1020);
        int size= yb.size();
        while (rest > 0 && i<size) {
            if (rest - yb[i].kc >=0) {//当前类别月饼可以全卖
                sjSum += yb[i].zsj;

            }
            else {//只能卖部分
                sjSum += yb[i].zsj / yb[i].kc * rest;
            }
            rest -= yb[i].kc;
            ++i;
        }
        cout << fixed << setprecision(2) << sjSum << endl;
    }
}
int main()
{       
    solve_1020();

    return 0;
}
