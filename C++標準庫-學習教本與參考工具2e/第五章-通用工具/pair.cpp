#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    //調用default int() double() 初始化p1
    pair<int, double> p1;  //同義於 pair<int,double> p1(0,0.0);
    //使用pair的constructor
    pair<int, string> p2(30, "Hello");
    //使用template的make_pair ---> make_pair會返回傳入的兩個值所組合的pair物件
    pair<int, double> p3 = make_pair(10, 3.14);

    //資料存取 pair.first pair.second 獲取第一 第二 個元素
    cout << p3.first << " " << p3.second << endl;
    /*
        pair的比較
        相等: 兩個pair的兩個元素都完全相等
        不相等:第一個元素有較高的優先度
    */
    pair<int, double> pA(10, 3.14);
    pair<int, double> pB(10, 3.14);
    cout << "pA == pB " << (pA == pB) << endl;

    return 0;
}