#include <iostream>
#include <vector>
#include <functional>//sort()中降序升序函数  可以用cmp自定义代替
#include<algorithm>//sort() 排序
#include <string>//int = stoi(string)  string = to_string(int)  string.push_back(char) string.append(string)
#include <cmath>//sqrt() 平方根  note:结果为浮点数
#include <iomanip>//setprecision()保留浮点数 小数位
#include<cstring>//memcpy(b,a,sizeof(a)) 数组赋值 a->b
#include <set>
using namespace std;

struct Node25{
    string add;
    int data;
    string next;
};
void solve_1025() {
    /*
    1.每k个元素进行反转
    2.最后不到k个元素不反转
    3.  ·nodes整理好顺序
        ·反转
        ·整理next地址 逆向
    */
    string address;
    int n, k;
    cin >> address >> n >> k;
    vector<Node25> nodes;
    for (int i = 0; i < n; ++i) {
        Node25 node;
        cin >> node.add >> node.data >> node.next;
        nodes.push_back(node);
    }
    string aim_add = address;//所找寻节点的地址
    int real_size = n;//有效节点长度
    for (int i = 0; i < n; ++i) {
        if (nodes[i].add == aim_add) {
            aim_add = nodes[i].next;//当前节点就是目标节点  更新下一目标地址
            continue;
        }
        if (aim_add == "-1") {//循环未结束 到达链表结尾后 仍在寻找节点 说明存在无效节点
            --real_size;
        }
        for (int j = 0; j < n; ++j) {//找到目标节点 0-n-1
            if (nodes[j].add == aim_add) {
                Node25 temp = nodes[j];
                nodes[j] = nodes[i];
                nodes[i] = temp;
                aim_add = nodes[i].next;
                break;
            }
      }
       
    }

        //反转
        int left = 0, right = left + k;
        while (right <= real_size) {
            for (int i = left, j = right - 1; i < j; ++i, --j) {
                Node25 temp = nodes[j];
                nodes[j] = nodes[i];
                nodes[i] = temp;
            }
            left += k;
            right = left + k;
        }
        //调整 next地址
        nodes[real_size - 1].next = "-1";
        for (int i = real_size - 2; i >= 0; --i) {
            nodes[i].next = nodes[i + 1].add;
        }

  
    for (int i = 0; i< real_size; ++i) {
        cout << nodes[i].add << " " << nodes[i].data << " " << nodes[i].next << endl;
    }
}
int main()
{       
    solve_1025();
    return 0;
}
