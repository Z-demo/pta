#include <iostream>
#include <vector>
#include <functional>//sort()中降序升序函数  可以用cmp自定义代替
#include<algorithm>//sort() 排序
#include <string>//int = stoi(string)  string = to_string(int)  string.push_back(char) string.append(string)
#include <cmath>//sqrt() 平方根  note:结果为浮点数  round() 四舍五入
#include <iomanip>//setprecision()保留浮点数 小数位
#include<cstring>//memcpy(b,a,sizeof(a)) 数组赋值 a->b
#include <set>
using namespace std;
void solve_1026() {
    /*
    clock tick 时钟打点 函数开始时为c1 结束时为c2
    CLK_TCK 每秒的时钟打点数
    runtime = (c2-c1)/CLK_TCK   C1 < C2
    hh:mm:ss（即2位的 时:分:秒）格式输出；不足 1 秒的时间四舍五入到秒。
    
    note: 简化代码
    
int main(){
	double a,b,c;
	int hh,mm,ss;	
	scanf("%lf %lf",&a,&b);
	c=(b-a)/100;
		hh=(int)(c/3600);
		mm=(int)((c-3600*hh)/60);
		ss=(int)(c-3600*hh-60*mm);
		if(c-3600*hh-60*mm-ss>=0.5)
			ss+=1;
	printf("%02d:%02d:%02d",hh,mm,ss);
}

    */
    int CT=100;
;
    int c1, c2,c3;
    cin >> c1 >> c2;
    c3 = c2 - c1;
    //double sec = (double)c3 / CT;
    //int seconds = round(sec);
    int seconds = round((double)c3 / CT);
    int rest = seconds;
    int h = 0, m=0, s = 0;
    while (rest !=0) {
        if (rest >= 3600) {//大于等于一小时
            h = rest / 3600;
            rest = rest % 3600;
        }
        else if (rest >= 60) {//大于等于一分钟
            m = rest / 60;
            rest = rest % 60;
        }
        else {
            s = rest;
            break;
        }

    }
    printf("%02d:%02d:%02d\n",h,m,s );

}
int main()
{       
    solve_1026();
    return 0;
}
