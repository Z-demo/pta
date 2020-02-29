#include <iostream>
using namespace std;

int main()
{
    int n;
    //cout << "请输入n的值!\n";
    cin >> n;
    int i = 0;
    if (n <= 0)
        exit(0);
    while (n != 1) {// 每一轮都需要进行奇数偶数判断
        if (n % 2 == 0) {//为偶数        
                n = n / 2;
                i++;
        }
        else if(n % 2 == 1) {//为奇数
                n = (3 * n + 1) / 2;
                i++;
        }
    }
    cout << i << endl;
    //cout << "经过" << i << "轮" << "n=" << n << endl;
}
