#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
int solve_1012() {
    /*
    A1 1.被5整除 2.是偶数  求和
    A2 1.被5除余1 2.交错求和
    A3 5除余2个数
    A4 5除余3数字平均数 小数点后一位
    A5 5除余4中的最大值

    note: 当A2交错求和的结果为0（而不是没进行求和的初始情况）
    */
    
    int n,data;
    cin >> n;
    if (n > 1000)
        return 0;
    int* d = new int[n];
    vector<int> a2, a4;
    int a1Sum=0,a2Sum=0, a3Num=0,a5Max=0;
    int a2Flag = 0;
    double a4Ave = 0;
    int a4Num=0, a4Sum = 0;
    //int a[1000];
    //vector<int> datas;
    int isAdd = 1;//A2中是加还是减 初次为+
    for (int i = 0; i < n;++i) {
        cin >>data;
        int deal = data % 5;
        switch (deal) {
        case 0:
            if (data % 2 == 0) {
                a1Sum += data;
            } 
            break;
        case 1:
            a2Flag = 1;
            if (isAdd) {
                a2Sum += data;
                isAdd = 0;//下次为-
            }
            else {
                a2Sum -= data;
                isAdd = 1;//下次为+
            }
            break;
        case 2:
            ++a3Num;
            break;
        case 3:
           a4Sum+=data;
           ++a4Num;
            break;
        case 4:
            if (data > a5Max)
                a5Max = data;
            break;
        
        }
        //*(d+i) = data;
    }
    a4Ave = (double)a4Sum / a4Num;
    a1Sum == 0 ? cout << "N " : cout << a1Sum<<" ";
    a2Sum == 0 && a2Flag==0 ? cout << "N " : cout << a2Sum << " ";
    a3Num == 0 ? cout << "N " : cout << a3Num << " ";
    a4Num == 0 ? cout << "N " : cout <<fixed<<setprecision(1)<< a4Ave << " ";
    a5Max == 0 ? cout << "N" : cout << a5Max;

    return 0;
}
int main()
{       
    solve_1012();
    return 0;
}
