#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
struct DCStudent {
    int num;
    int dg;
    int cg;
    int total;
};
void swap(DCStudent &s1, DCStudent &s2) {
    DCStudent temp = s1;
    s1 = s2;
    s2 = temp;
}
//return a>b 表示降序，return a<b表示升序
bool cmp(DCStudent a, DCStudent b) {
    if (a.total != b.total) return a.total > b.total;//总分降序
    else if (a.dg != b.dg) return a.dg > b.dg;//同分德降序
    else return a.num < b.num;//同分同德考号升序

}

/*自定义的冒泡排序超时
*/
//void DCSort(vector<DCStudent> &stu) {
//    //一类到四类从高到低排序。总分相同时，1按其德分降序；若德分也并列，2则按准考证号的升序。
//    int size = stu.size();
//    for (int i = 0; i < size-1; ++i) {
//        for (int j = 0; j < size - i - 1; ++j) {
//            if (stu[j].total < stu[j + 1].total) {//总分低后移
//                swap(stu[j], stu[j + 1]);
//            }
//            else if (stu[j].total == stu[j + 1].total) {
//                if (stu[j].dg < stu[j + 1].dg) {//同分德低后移
//                    swap(stu[j], stu[j + 1]);
//                }
//                else if (stu[j].dg == stu[j + 1].dg && stu[j].num > stu[j + 1].num) {//同分同德号大后移
//                    swap(stu[j], stu[j + 1]);
//                }
//
//            }
//        }
//    }
//
//}
void DCPrint(vector<DCStudent> stu) {
    for (int i = 0; i < stu.size(); ++i) {
        /*cout << stu[i].num << " " << stu[i].dg << " " << stu[i].cg << endl;*/
        printf("%d %d %d\n", stu[i].num, stu[i].dg, stu[i].cg);
    }
}
void solve_1015() {
    /*
    德分 才分
    1.N 人数
    2.L 分数线 被考虑资格
    3.H 优先录取线 才德均过H 才德全尽 总分高到低 第一类
    4.德过H 才不过H 德胜才 总分排序 第二类
    5.德才均不过H 德胜才 才德兼亡 总分排序 第三类
    6.才德仅仅过N 排序 第四类
    7.一类到四类从高到低排序。总分相同时，1按其德分降序；若德分也并列，2则按准考证号的升序。
    */
    int n, l, h;
    cin >> n >> l >> h;
    vector<DCStudent> students;
    vector<DCStudent> stu1,stu2,stu3,stu4;
    int m = 0;//过L线人数
    for (int i = 0; i < n; ++i) {
        DCStudent stu;
        //cin >> stu.num >> stu.dg >> stu.cg;
        scanf("%d%d%d", &stu.num, &stu.dg, &stu.cg);
        stu.total = stu.dg + stu.cg;//总分
        if (stu.dg >= l && stu.cg >= l) {//初步资格
            ++m;
            if (stu.dg >= h && stu.cg >= h) {//第一类
                stu1.push_back(stu);
            }
            else if (stu.dg >= h && stu.cg < h) {//第二类
                stu2.push_back(stu);
            }
            else if(stu.dg < h && stu.cg < h && stu.dg>=stu.cg){//第三类
                stu3.push_back(stu);
            }
            else {//第四类
                stu4.push_back(stu);
            }
        }
        
    }
    cout << m << endl;
  /*  DCSort(stu1);
    DCSort(stu2);
    DCSort(stu3);
    DCSort(stu4);*/
    sort(stu1.begin(), stu1.end(), cmp);
    sort(stu2.begin(), stu2.end(), cmp);
    sort(stu3.begin(), stu3.end(), cmp);
    sort(stu4.begin(), stu4.end(), cmp);

    DCPrint(stu1);
    DCPrint(stu2);
    DCPrint(stu3);
    DCPrint(stu4);
}
int main()
{       
    solve_1015();
    return 0;
}
