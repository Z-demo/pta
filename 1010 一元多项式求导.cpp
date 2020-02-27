#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>//可以将字符串转化为整型
#include <cmath>
using namespace std;
void solve_1010() {
    string str;
    vector<int> datas;
    int xi,zhi;
    int a[20];
    //cin >> a;
    int p = 0;
    while (cin>>xi>>zhi) {
       //cin >> xi>>zhi;
        if (zhi == 0 && p == 0) {
            cout << "0 0";
            break;
        }else if (zhi != 0) {
           int x= xi * zhi, z= zhi - 1;
           if (p == 0) {
               cout << x << " " << z;
               p = 1;
           }      
           else 
               cout <<" "<< x << " " << z;
       }
       if (cin.get() == '\n')
           break;
    }

}


int main()
{       
    solve_1010();
    return 0;
}
