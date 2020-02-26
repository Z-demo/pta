#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>//可以将字符串转化为整型
using namespace std;
void solve_1006() {
    //const char* n = {}
    int w = 0;//当前位数 0 2 3 个 十 百
    int n = 0;
    vector<string> results;//分别为获取个十百位字符串 然后倒序输出
    cin >> n;
    while (n!= 0) {
        if (w == 0) {
            int g = n % 10;
            string geStr ;
            for (int i = 1; i <= g; ++i) {
                geStr.append(to_string(i));
            }
            results.push_back(geStr);
        }
        else if (w == 1) {
            int s = n % 10;
            string sStr;
            for (int i = 1; i <= s; ++i) {
                sStr.append("S");
            }
            results.push_back(sStr);
            
        }
        else if (w == 2) {
            int b = n % 10;
            string bStr;
            for (int i = 1; i <= b; ++i) {
                bStr.append("B");
            }
            results.push_back(bStr);
        }
        w++;
        n = n / 10;
    }
    for (int i = results.size()-1; i >= 0; --i) {
        cout << results[i];
    }
    cout << endl;
}

int main()
{       
    solve_1006();
    return 0;
}
