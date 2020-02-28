#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
int solve_1013() {
    /*
    找到低m个到第n个素数 
    */
    int m, n;
    cin >> m >> n;
    if (m > n || n > pow(10, 4))
        return 0;
    //for(int m=0)
    int i=2,j,cnt=0,column=0;
    int isEnd = 0;
    while (!isEnd) {
        for ( j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {//能被2到sqrt(i) 之间的数整除 则不是素数
                break;
            }

        }
        if (j > sqrt(i)) {//两种情况 1.初始>sqrt(i) i必定不可被2到sqrt(i)之间数整除  2.for循环遍历结束 i不能被 2到sqrt(i)数整除
            ++cnt;//素数的数量+1
            if (cnt >= m && cnt <= n) {
                cout << i;
                ++column;//当前数在第几列
                if (column == 10) {
                    cout << endl;
                    column = column % 10;
                }
                else {
                    if(cnt!=n)
                        cout << " ";
                }
            }
        }
        if (cnt == n)
            isEnd = 1;
        ++i;
    }
    return 0;
}
int main()
{       
    solve_1013();
    return 0;
}
