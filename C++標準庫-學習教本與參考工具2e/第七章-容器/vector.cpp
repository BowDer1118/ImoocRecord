#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    //v1初始化為1,2,3,4
    vector<int> v1({1, 2, 3, 4});
    //v1被重新指派為10,20,30
    v1.assign({10, 20, 30});

    //使用iterator訪問vector
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << v1.front() << " ";
    cout << v1[1] << " ";
    cout << v1.back() << endl;

    vector<int>::iterator it = v1.begin();
    it++;  //此時指向v1[1]

    //插入並返回-100的位置
    it = v1.insert(it, -100);
    cout << *it << endl;

    for (auto it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    it++;  //此時指向v1[2]
    //從it前方插入300並回傳300的位置
    it = v1.emplace(it, 300);
    cout << *it << endl;

    for (auto it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    //刪除it指向的元素 並刪除後下一個元素
    it = v1.erase(it);
    cout << *it << endl;

    for (auto it = v1.begin(); it != v1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //清除vector
    v1.clear();

    if (v1.empty()) {
        cout << "vector is empty" << endl;
    }
    return 0;
}