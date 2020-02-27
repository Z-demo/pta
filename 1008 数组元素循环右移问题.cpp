
#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>//可以将字符串转化为整型
#include <cmath>
using namespace std;
void solve_1008() {
    int N,M,t;
    cin >> N >> M;

    //int a[n+m+1];
    //int a[100];
  /*  int* b=new int;
    *b = 5;
    cout << "b=" << *b<<endl;*/
    int* a = new int[N];//动态数组
    for (int i = 0; i < N; ++i) {
        cin >> *(a+i);    
        //cout << *(a + i) << endl;
    }
    if (M > N)
        M = M % N;//调整m大小

    //前 N-M部分  和后M部分 分别逆序   然后在整个逆序
    for (int i = 0, j = N - M - 1; i < j; i++, j--) {
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    for (int i = N - M, j = N - 1; i < j; i++, j--) {
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    for (int i = 0, j = N - 1; i < j; i++, j--) {
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    for (int i = 0; i < N; i++) {
        printf("%d", a[i]);
        if (i < N - 1) printf(" ");
        else printf("\n");
    }
 

    delete[] a;//删除数组
}
int main()
{       
    solve_1008();
    return 0;
}
