#include <iostream>
#include <vector>
#include <string>//可以将字符串转化为整型
using namespace std;
// PTA.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>//可以将字符串转化为整型
using namespace std;

struct Student04 {
    string name;
    string pNum;
    int grade;
};
void solve_1004_2() {
    int n;
    int max = 0, min = 101;
    //scanf("%d", &x);
    cin >> n;
    Student04 maxStu, minStu;
    for (int i = 0; i < n; ++i) {
        vector<string> info;
        string name, num;
        int grade;
        cin >> name >> num >> grade;

        if (grade > max) {
            max = grade;
            maxStu.name = name;
            maxStu.pNum = num;
            maxStu.grade = grade;
        }
        if (grade < min) {
            min = grade;

            minStu.name = name;
            minStu.pNum = num;
            minStu.grade = grade;
        }
    }
    cout << maxStu.name << " " << maxStu.pNum<<endl;
    cout << minStu.name << " " << minStu.pNum << endl;
}

int main()
{       
    solve_1004_2();
    return 0;
}



