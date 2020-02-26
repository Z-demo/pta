#include <iostream>
#include <vector>
#include <string>//可以将字符串转化为整型
using namespace std;

void solve_1004() {
    int n;
    int l = 3;
    int maxIndex, minIndex;
    int max = 0, min = 101;
    //scanf("%d", &x);
    cin >> n;
    vector<vector<string>> infos;
    //getchar();
    for (int i = 0; i < n; ++i) {
        vector<string> info;
        string name, num;
        int grade;
        cin >> name >> num >> grade;
        info.push_back(name);
        info.push_back(num);
        info.push_back(to_string(grade));
        infos.push_back(info);
 
        if (grade > max) {
            max = grade;
            maxIndex = i;
        }
        if (grade < min) {
            min = grade;
            minIndex = i;
        }
    }
    vector<string> maxInfo=infos.at(maxIndex);
    vector<string> minInfo= infos.at(minIndex);
    cout << maxInfo.at(0) << " " << maxInfo.at(1) << endl;
    cout << minInfo.at(0) << " " << minInfo.at(1) << endl;

  
}

int main()
{       
    solve_1004();
    return 0;
}
