#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>//可以将字符串转化为整型
#include <cmath>
using namespace std;

vector<int> sushu(int m) {
    vector<int> s;
    if (m < 2)
        return s;
  
    s.push_back(2);
    int k,j;
    for (int i = 3; i <= m; ++i) {
       k = sqrt(i);
       for (j = 2; j <= k; j++)
           if (i % j == 0)
               break;
       if (j > k)
           s.push_back(i);
   }
    
   /* for (int i = 3; i <=m; ++i) {  //不能把平方根放入 k中 会损失精度
        for (j = 2; j < sqrt(i); ++j) {
            if (i % j == 0) {
                break;
            }      
        }
        if (j>sqrt(i))
            s.push_back(i);
      
    }*/
    return s;
}
void solve_1007() {
    int n = 0;
    cin >> n;
    int duishu=0;
    vector<int> s = sushu(n);//素数序列
    for (vector<int>::iterator it = s.begin(); it < s.end()-1; ++it) {
        if (*(it + 1) - *it == 2) {
            duishu++;
        }
    }
    cout<<duishu;
}

int main()
{       
    solve_1007();
    return 0;
}
