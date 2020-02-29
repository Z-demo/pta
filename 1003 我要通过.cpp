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
    /*
    难以理解的题目类型
    
    仔细想一下，应该“如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。”这句话的问题。

（1）这句话说的是任意满足条件的aPbTc正确，则可以得到另外一个正确的表达式aPbATca。

（2）那么最简单的正确的表达式是PAT（b的初始值是A）,可以得到PAAT也是正确的，延伸出PAAAT正确。

（3）在第（2）条是在“a”和“c”为空的情况下得到的，那么在“a”“c”赋值的情况下，假设“a” “c”都为“A”，那么“APATA”是正确的，可以得到“APAATAA”也是正确的，延伸出“APAAATAAA”也是正确的，到这，是不是发现了一些规律呢？还没有发现吗，好吧，再来看

（4）“a”赋值“A”c赋值“AA”（这样设置的原因是在第（3）条中“a”和“c”设置的是一样的，所以在本条中希望设置的不一样，以体现规律的适用性），最简单的是“APAATAA”,可以得到“APAAATAAA”.可能有人会疑问为什么在“a”赋值“A”c赋值“AA”的情况下，最简单的不是“APATAA”呢?因为如果把它写成“aPbATca”形式，找不到一个“aPbTc”形式来验证它的正确性。

（5）得出结论，每一次的延伸，b都是多了一个“A”，同时“ca”也是“a”的翻倍，所以可以得到结论a*b = c,符合这个条件的就是对的，不符合就是错的。

（6）原来这个题目看起来这么难，分析到最后，仅仅是一个找规律的题目而已啊。生活中有很多看似很难的事情，多尝试一下，同样可以成功的！！！
————————————————
版权声明：本文为CSDN博主「piaoliangjinjin」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/piaoliangjinjin/article/details/80634514
    */
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
