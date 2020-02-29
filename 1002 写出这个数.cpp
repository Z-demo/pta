#include <iostream>
using namespace std;

int main()
{
    /*
    1.求和
    2.取这个和的各位
    
    note:字符数组末尾有一个'\0'
    */
    
    string d[] = { "ling","yi" };
    const char* p[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
    char a[101];
    cin >> a; //字符数组 或者string接收 一行数据
    int i = 0,sum=0;
    while (a[i] != '\0') {
        sum += a[i] - '0';
        ++i;
    }
    if (sum == 0) {
        cout << p[0];
        return 0;
    }
   // cout << "sum=" << sum << endl;
    int j = 0, b[11];//可以用集合 或者动态数组
    while (sum != 0) {
        b[j++] = sum % 10;
        sum = sum / 10;
    }

    for (int i = j-1; i>=0; --i) {
        cout << p[ b[i] ];
        if (i >0)
            cout << " ";
    }

  
}
