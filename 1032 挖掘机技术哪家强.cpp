#include <iostream>
#include <vector>
#include <functional>//sort()中降序升序函数  可以用cmp自定义代替
#include<algorithm>//sort() 排序 
#include <string>//int = stoi(string)  string = to_string(int)  string.push_back(char) string.append(string)
#include <cmath>//sqrt() 平方根  note:结果为浮点数  round() 四舍五入
#include <iomanip>//setprecision()保留浮点数 小数位
#include<cstring>//memcpy(b,a,sizeof(a)) 数组赋值 a->b
#include <set>
using namespace std;
void solve_1032() {
    int a[100000] = {0}, n;
    cin >> n;
    int num, grade,maxGrade=0,maxNum=0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &num, &grade);
        a[num] += grade;
        if (a[num] > maxGrade) {
            maxGrade = a[num];
            maxNum = num;
        }
            
    }
    printf("%d %d\n", maxNum, maxGrade);

}

int main()
{       
   solve_1032();
    return 0;
}
