#include <iostream>
#include <vector>
#include <functional>
#include<algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
void solve_1014() {
    /*
    1.星期 ABCDEFG 123456日 前二字符
    2.时 0-9 A-N 0-9 10-23 前二字符
    3.分 英文字母 第几对相同 为第几分钟 0开始 后二字符


     note : 巨坑第二个节点  缺了break ,在找到小时后 要break  在找到分针后 要break
    */
    //const string WEEKS[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
    const string WEEKS[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    string s1, s2, s3, s4;
    cin>>s1>>s2>>s3>>s4;
    int length1 = s1.size() < s2.size() ? s1.size() : s2.size();
    int length2 = s3.size() < s4.size() ? s3.size() : s4.size();
   /* for (int i = 0; i < length1; ++i) {
        
    }*/
    int i = 0,cnt=0;
    while (i != length1) {
        if (s1.at(i) == s2.at(i)) {
            if (cnt == 0 && s1.at(i) >= 'A' && s1.at(i) <= 'G') {
                ++cnt;
                int index = s1.at(i) - 'A';
                cout << WEEKS[index] << " ";
            }
            else if (cnt == 1) {
                if (s1[i] >= '0' && s1.at(i) <= '9') {
                    printf("%02d:", (s1[i] - '0'));
                    //int hour = s1.at(i) - '0';
                    ////if (hour < 10)
                    //cout << "0" << hour << ":"; 
                    break;

                }
                else if (s1.at(i) >= 'A' && s1.at(i) <= 'N') {
                   /* int hour = s1.at(i) - 'A' + 10;
                    cout << hour << ":";*/
                    printf("%02d:", (s1[i] - 'A' + 10));
                    break;
                }
            }
        }
        ++i;
    }
    i = 0;
    while (i != length2) {
        if (s3.at(i) == s4.at(i)) {
            if ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z')) {
               /* if (i <= 9)
                    cout << "0"<<i<<endl;
                else if(i<60)
                    cout << i << endl;*/
                printf("%02d", i);
                break;
            }
            
        }
        ++i;
    }

}
int main()
{       
    solve_1014();
    return 0;
}
