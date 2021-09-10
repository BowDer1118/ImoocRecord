#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
    搜尋子區間(First Subrange)
    1.search(Iterator beg,Iterator end,Iterator searchBeg,Iterator searchEnd)
    2.search(Iterator beg,Iterator end,Iterator searchBeg,Iterator searchEnd,BinaryPredicate op)

    搜尋範圍: 在[beg,end)中 找[searchBeg,end)區段
    
    版本1:返回在[beg,end)區間中 第一個 完全吻合子區間 的 位置 
    版本2:返回在[beg,end)區間中 第一個 [searchBeg,searchEnd)中所有元素 都讓BinaryPredicate 為true 的 位置

    找不到則都返回 container.end()

    BinaryPredicate 的形式為 bool op(elem,searchElem){...}
    elem 是[beg,end) 區間的元素
    searchElem 是[searchBeg) 區間的元素
*/

int main() {
    //重新配置vector中的元素(會將原本的全部清除 指派新的元素進入)
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v2 = {3, 4, 5};

    //找v2區間存在於v1中的哪個位置
    auto pos = search(v1.begin(), v1.begin(), v2.begin(), v2.end());
    if (pos != v1.end()) {
        cout << *pos << endl;  //3
    }

    //在v1中找一個區間 使得此區間的值 都大於v1區間
    pos = search(v1.begin(), v1.end(), v2.begin(), v2.end(), [](int elem, int searchElem) -> bool { return elem > searchElem; });
    if (pos != v1.end()) {
        cout << distance(v1.begin(), pos) << endl;  //3 --->v1[3]
    }
    return 0;
}