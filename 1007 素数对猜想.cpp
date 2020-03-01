#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>//可以将字符串转化为整型
#include <cmath>
using namespace std;

void solve_1007_2() {
    int n;
    //scanf("%d", &n);
    cin >> n;
    int j;
    int pre=0, next=0,cnt=0;
    for (int i = 2; i <= n; ++i) {
        for (j = 2; j < sqrt(i); ++j)
            if (i % j == 0)
                break;
        if (j > sqrt(i)) {//为素数
            if (pre == 0)
                pre = i;
            else {
                next = i;
                next - pre == 2 ? cnt++, pre = next : pre =next;
            }
                
        }

    }
    printf("%d", cnt);
}

int main()
{       
    solve_1007_2();
    return 0;
}
