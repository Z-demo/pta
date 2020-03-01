#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>//可以将字符串转化为整型
using namespace std;


#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>//可以将字符串转化为整型
using namespace std;

void solve_1005_2() {
    /*
    1.接收所有输入数据
    2.顺序算路径 然后向后比对 重复的覆盖为0
    */
    int n = 0;
    cin >> n;
    vector<int> datas;//存放所有输入数据
    //vector<vector<int>> paths;//存放每个输入数据的覆盖路径path（不包括它本身）
    for (int i=0; i < n; ++i) {
        int data;
        cin >> data;
        datas.push_back(data);
    }
    for (int i = 0; i < n; ++i) {
        int data = datas[i];
        if (data != 0) {//不为0计算覆盖路径
            while (data != 1) {
                data % 2 == 0 ? data = data / 2 : data = (3 * data + 1)/2;
                for (int j = 0; j < n; ++j) {
                    if (datas[j] != 0 && datas[j] == data) {//待比对的其他输入数据 不为0 且被data路径覆盖
                        datas[j] = 0;//被覆盖的数据 其路径为data的子集 所以没必要再算被覆盖数据的路径
                    }
                }
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
    solve_1005_2();
    return 0;
}
