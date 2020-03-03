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
bool cmp_feiDiZeng(int a, int b) {
    return a > b;
}
bool cmp_feiDiJian(int a, int b) {
    return a < b;
}
int sumArray(int a[],int n) {
    int k = 1,sum=0;
    for (int i = n - 1; i >= 0; --i) {
        sum += a[i] * k;
        k *= 10;
    }
    return sum;
}
void solve_1019() {
    /* 
    例  6767
    1、 数字1：非递增 a>=b   7766
        数字2：非递减 a<=b   6677

    2、 数字1-数字2  7766 - 6677 = 1089
      下一轮 直到 8532 - 2358 = 6174
                  7641 - 1467 = 6174
                  7641 - 1467 = 6174  ....一直重复
    */
    int a[4],b[4],c[4];
   /* for (int i = 0; i < 4; ++i) {
        cin >> a[i];
    }*/
    int result;
    cin >> result;
    string str = to_string(result);
   
    do{//测试点5 6174
        int re=0;
        re = result;
        for (int i = 3; i >= 0; --i) {
            a[i] = re % 10;
            re /= 10;
        }
        if (a[1] == a[2] && a[2] == a[3] && a[3] == a[0]) {
            cout << str << " - " << str << " = " << "0000";     //这样写如果0000不带引号的话，第一个测试点错误   
            break;
        }
        sort(a, a + 4, cmp_feiDiZeng);
        memcpy(b, a, sizeof(a));//得到非递增b
        int sumb = sumArray(b, 4);
        sort(a, a + 4, cmp_feiDiJian);
        memcpy(c, a, sizeof(a));//得到非递增c
        int sumc= sumArray(c, 4);
        result = sumb - sumc;
        printf("%04d - %04d = %04d\n", sumb, sumc, result);
        //cout << sumb << " - " << sumc << " = " << result<<endl;
    } while (result != 6174);
   
    
}
int main()
{       
    solve_1019();
  /*  cout << "start" << endl;
    cout << 6174 % 10<< endl;
    cout << 6174 % 100/10 << endl;
    cout << 6174 % 1000/100 << endl;
    cout << 6174  /1000 << endl;*/
    return 0;
}
