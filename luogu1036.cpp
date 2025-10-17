#include <iostream>
#include <vector>
#include <cmath> // 添加cmath头文件用于sqrt函数
using namespace std;

// 添加缺失的大括号
void find_combinations(vector<int>& nums, int start, int k, 
                      vector<int>& current, vector<vector<int>>& result) {
    if (k == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);
        find_combinations(nums, i + 1, k - 1, current, result);
        current.pop_back();
    }
}

// 添加素数判断函数
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    int limit = sqrt(n) + 1;
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    vector<vector<int>> result;
    vector<int> current;
    find_combinations(nums, 0, k, current, result);
    
    int counter = 0;
    // 遍历每个组合
    for (const auto& combination : result) {
        int sum = 0;
        // 计算组合内元素和
        for (int num : combination) {
            sum += num;
        }
        // 判断和是否为素数
        if (isPrime(sum)) {
            counter++;
        }
    }
    
    cout << counter << endl;
    return 0;
}