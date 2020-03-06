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
void solve_1030() {
    /*
    1.如果 M≤mp
    */
  long int N,p,cnt=0;	cin>>N>>p;
	vector<int> v(N);
	for(int i=0;i<N;i++)	cin>>v[i];
	sort(v.begin() ,v.end() );
	for(int i=0;i<N;i++){
		for(int j=i+cnt;j<N;j++){
			if(v[j]>p*v[i])	break;
			if(j-i+1>cnt)	cnt=j-i+1;
		}
	}
	cout<<cnt;
}
int main()
{       
    solve_1030();
    return 0;
}
