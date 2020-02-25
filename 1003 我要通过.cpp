#include <iostream>
#include <vector>
using namespace std;
const char pat[3] = { 'P','A','T' };
bool isPat(char c) {
    int i;
    for (i = 0; i < 3; ++i) {
        if (c == pat[i])
            return true;
    }
    return false;
}
void solve() {
    int x;
    //scanf("%d", &x);
    cin >> x;
    getchar();
    vector<string> results;
    for (int i = 0; i < x; i++) {
        int Aqnum = 0, Aznum = 0, Ahnum = 0;//前中后A的数量
        int P, A, T;
        P = A = T = 0; // P A T 的个数
        int rp = 1; // 控制 是 P 前 还是 P~T之间 和 T 之后的变量    【1 2 3 前中后】
        int cnd = 1; // 若含有其他字符就改为 0
        int isP = 1;//是否为p左t右
        int isT = 0;
        for (char s; s = getchar(), s != '\n';) {
            if (s == 'P') {
                P++;
                rp = 2;//到中间部位
                if (isT)
                    isP = 0;
            }
            else if (s == 'A') {
                A++;
            }
            else if (s == 'T') {
                T++;
                rp = 3;//到后部
                isT = 1;
            }
            else
                cnd = 0;
            //s == 'P' ? P++, rp = 2 : s == 'A' ? A++ : s == 'T' ? T++, rp = 3 : cnd = 0; // 可以使用if来写 其实也就是这个意思。
            switch (rp) {
            case 1:Aqnum++; break; // 前
            case 2:if (s != 'P') Aznum++; break; // 中
            case 3:if (s != 'T') Ahnum++; break; // 后
            }
        }
        if (P == 1 && A && T == 1 && Aqnum * Aznum == Ahnum && cnd && isP) // 只有1个P 只有1个T 并且满足乘法 还满足 没有其他字符的话
            //printf("YES\n"); // 我我我~~
            results.push_back("YES");
        else  // 否则
            //printf("NO\n"); // ==楼上嫌弃我~
            results.push_back("NO");
    }
    for (vector<string>::iterator iter = results.begin(); iter != results.end(); iter++)
    {
        cout << *iter << endl;
    }
}

int main()
{       
    solve();
    return 0;
}
