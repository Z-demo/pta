#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>//可以将字符串转化为整型
using namespace std;

vector<int> solve_1001(int n) {
    //int n;
    vector<int> path;
    //cout << "请输入n的值!\n";
    //cin >> n;
    int i = 0;
    if (n <= 0)
        exit(0);
    while (n != 1) {
        if (n % 2 == 0) {//为偶数        
            n = n / 2;
            i++;
        }
        else if (n % 2 == 1) {//为奇数
            n = (3 * n + 1) / 2;
            i++;
        }
        path.push_back(n);
    }
    //cout << i << endl;
    return path;
}
void solve_1005() {
    //1.
    int n = 0;
    cin >> n;
    vector<int> datas;//存放所有输入数据
    vector<vector<int>> paths;//存放每个输入数据的覆盖路径path（不包括它本身）
    for (int i=0; i < n; ++i) {
        int data;
        cin >> data;
        vector<int> path = solve_1001(data);
        paths.push_back(path);
        datas.push_back(data);
    }
    //vector<int> path = solve_1001(datas[0]);
    for (int i = 0; i < paths.size(); ++i) {
        vector<int> path = paths[i];
        for (vector<int>::iterator it = path.begin(); it < path.end(); ++it) {
            for (int i = 0; i < n; ++i) {
                if (datas[i] != 0 && datas[i] == *it)//原输入数据中 包含被覆盖路径中的数（那么就不是关键数）
                    datas[i] = 0;//该数被覆盖 则置为0
            }
        }

    }
    int flag = 0;//判断是否是第一个数 第一个数则前面没空格
    sort(datas.begin(), datas.end(), greater<int>());
    for (int i = 0; i < datas.size(); ++i) {
        if (datas[i] != 0) {
            if (flag != 0) {
                cout << " ";
                
            }
            flag = 1;
            cout<< datas[i];
        }

    }
    
}

int main()
{       
    solve_1005();
    return 0;
}
