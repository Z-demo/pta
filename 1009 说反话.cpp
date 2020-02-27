#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>//可以将字符串转化为整型
#include <cmath>
using namespace std;
void solve_1009() {
    vector<string> sentence;
    string str;
    getline(cin, str);

    string word="";
    for (int i = 0; i < str.size(); ++i) {
        char c = str.at(i);
        if (c != ' ') {
            word.push_back(str.at(i));
        }
        else {
            sentence.push_back(word);
            //cout << "word = " << word << endl;
            word = "";//初始化
        }
        if(i==str.size()-1)
            sentence.push_back(word);
            
    }
    for (vector<string>::reverse_iterator it = sentence.rbegin(); it != sentence.rend();++it) {
        if (it == sentence.rend()-1)
            cout << *it << endl;
        else {
            cout << *it << " ";
        }
           
    }
}
int main()
{       
    solve_1009();
    return 0;
}
