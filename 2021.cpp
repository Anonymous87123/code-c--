#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int main() {
    vector<int> list0 = {2, 0, 2, 1, 20, 21};
    set<string> unique_numbers;
    // 1. 生成所有可能的排列
    sort(list0.begin(), list0.end());  // 必须先排序才能使用 next_permutation
    do {
        // 2. 将排列转换为字符串
        string num_str;
        for (int num : list0) {
            num_str += to_string(num);
        }
        // 3. 检查是否满足8位数且首位不为0
        if (num_str.length() == 8 && num_str[0] != '0') {
            unique_numbers.insert(num_str);
        }
    } while (next_permutation(list0.begin(), list0.end()));
    // 4. 输出唯一8位数的数量
    cout << unique_numbers.size() << endl;
    return 0;
}