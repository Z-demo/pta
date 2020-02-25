#include <iostream>
using namespace std;

int main()
{
    string d[] = { "ling","yi" };
    const char* p[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
    char a[101];
    cin >> a;
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
    int j = 0, b[11];
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
