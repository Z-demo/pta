#include <functional>
#include<algorithm>
#include <string>//可以将字符串转化为整型
#include <cmath>
using namespace std;
int solve_1011() {
    int n;
    cin >> n;
    if (n > 10)
        return 0;
    double a, b, c;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b >> c;
        //a+b>c?cout<<"true":
        if (a + b > c)
            cout<<"Case #"<<i<<": true"<<endl;
        else
            cout << "Case #" << i << ": false" << endl;
    }
    return 0;
}
int main()
{       
    solve_1011();
    return 0;
}
