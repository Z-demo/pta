void solve_1024() {
    /*
    1.+1.23400E-03  zf1 num1 E zf2 num2
    2.E后面 00-09 而不是1-9
    3.先算位移数 L 再分析小数点“.” 加到什么位置
    */
    string dataStr;
    cin >> dataStr;
    char zf1,zf2;
    string num1, num2;
    zf1 = dataStr[0];
    int size = dataStr.size();
    int isNum1 = 1;//是否出在num1区间
    for (int i = 1; i < size; ++i) {
        if (dataStr[i] != 'E' && isNum1 == 1&& i!=2)
            num1.push_back(dataStr[i]);
        else if (dataStr[i] == 'E') {
            isNum1 = 0;
            zf2 = dataStr[++i];
        } 
        else if(isNum1 == 0)
            num2.push_back(dataStr[i]);

    }
    if (zf1 == '-')
        cout << "-";
    int size1 = num1.size();
    int size2 = num2.size();
    int L = 0;
    if (num2 == "00")
        cout << "1" << endl;
    else {
        //确定位移数
        
        if (num2[0] == '0') {//01-09
            L = num2[1] - '0';
        }
        else {// 10-9999
            L = stoi(num2);
        }
    }
    if (zf2 == '+') {//E为正 前移L位
            cout << num1[0];//先输出原整数位
            for (int i = 1; i < size1; ++i) {
                cout << num1[i];
                --L;
                if (L == 0 && i!=size1-1)//注意 正好位移到有效位数最后一位 就不需要小数点
                    cout << ".";
            }
            while (L > 0) {
                cout << "0"; --L;
            }
            cout << endl;
    }
    else {//后移L位
        cout << "0."; --L;
        while (L > 0) {
            cout << "0"; --L;
        }
        cout << num1 << endl;
    }
}

int main()
{       
    solve_1024();
    return 0;
}
