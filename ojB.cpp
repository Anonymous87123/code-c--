#include<bits/stdc++.h>
using namespace std;

// 移除字符串中的逗号
string removeCommas(const string& s) {
    string res = "";
    for (char c : s) {
        if (c != ',') res += c;
    }
    return res;
}

// 比较两个大数（逆序存储）的大小
int cmp(vector<int>& a, vector<int>& b) {
    if (a.size() != b.size()) {
        return a.size() > b.size() ? 1 : -1;
    }
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }
    return 0;
}

// 大数乘法
vector<int> multiply(vector<int>& a, vector<int>& b) {
    int n = a.size() + b.size();
    vector<int> res(n, 0);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            res[i + j] += a[i] * b[j];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

// 大数加法
vector<int> add(vector<int>& a, vector<int>& b) {
    int n = max(a.size(), b.size());
    vector<int> result(n, 0);
    int carry = 0;
    for (int i = 0; i < n; i++) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        result[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry > 0) result.push_back(carry);
    return result;
}

// 大数减法（假设a >= b）
vector<int> sub(vector<int>& a, vector<int>& b) {
    vector<int> result(a.size(), 0);
    int borrow = 0;
    for (int i = 0; i < a.size(); i++) {
        int diff = a[i] - borrow;
        if (i < b.size()) diff -= b[i];
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = diff;
    }
    while (result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}

// 大数乘以整数
vector<int> mul_int(vector<int>& a, int b) {
    vector<int> result;
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        int product = a[i] * b + carry;
        result.push_back(product % 10);
        carry = product / 10;
    }
    while (carry > 0) {
        result.push_back(carry % 10);
        carry /= 10;
    }
    return result;
}

// 大数除法，返回商（整数），余数在remainder中
vector<int> divide(vector<int>& dividend, vector<int>& divisor, vector<int>& remainder) {
    if (cmp(dividend, divisor) < 0) {
        remainder = dividend;
        return vector<int>(1, 0);
    }
    
    // 将被除数复制一份，避免修改原数组
    vector<int> temp = dividend;
    
    // 从高位开始处理
    vector<int> quotient;
    
    // 计算商的位置
    int len_diff = temp.size() - divisor.size();
    quotient.resize(len_diff + 1, 0);
    
    // 对齐除数
    vector<int> shifted_divisor = divisor;
    shifted_divisor.insert(shifted_divisor.end(), len_diff, 0);
    
    for (int i = len_diff; i >= 0; i--) {
        // 估算当前位的商
        int q = 0;
        
        // 当当前部分大于等于移位后的除数时，减去除数
        while (cmp(temp, shifted_divisor) >= 0) {
            temp = sub(temp, shifted_divisor);
            q++;
        }
        
        quotient[i] = q;
        
        // 将除数右移一位
        if (i > 0) {
            shifted_divisor.erase(shifted_divisor.begin());
        }
    }
    
    remainder = temp;
    
    // 去掉前导零
    while (quotient.size() > 1 && quotient.back() == 0) {
        quotient.pop_back();
    }
    
    return quotient;
}

// 打印乘法结果
void print_mul(vector<int>& res) {
    if (res.size() == 1 && res[0] == 0) {
        cout << "0" << endl;
        return;
    }
    
    string s = "";
    for (int i = res.size() - 1; i >= 0; --i) {
        s += to_string(res[i]);
    }
    
    // 添加逗号
    string formatted = "";
    int count = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        formatted = s[i] + formatted;
        count++;
        if (count % 3 == 0 && i != 0) {
            formatted = "," + formatted;
        }
    }
    
    cout << formatted << endl;
}

// 打印除法结果
void print_division_result(vector<int>& integer_part, vector<int>& decimal_part) {
    // 处理整数部分
    string int_str = "";
    for (int i = integer_part.size() - 1; i >= 0; i--) {
        int_str += to_string(integer_part[i]);
    }
    
    if (int_str.empty()) int_str = "0";
    
    // 为整数部分添加逗号
    string formatted_int = "";
    int count = 0;
    for (int i = int_str.length() - 1; i >= 0; i--) {
        formatted_int = int_str[i] + formatted_int;
        count++;
        if (count % 3 == 0 && i != 0) {
            formatted_int = "," + formatted_int;
        }
    }
    
    // 处理小数部分
    string dec_str = "";
    for (int i = 2; i >= 0; i--) {
        dec_str += to_string(decimal_part[i]);
    }
    
    // 四舍五入
    if (decimal_part[3] >= 5) {
        // 需要进位
        int carry = 1;
        for (int i = 0; i < 3; i++) {
            int digit = (dec_str[2 - i] - '0') + carry;
            if (digit >= 10) {
                digit -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            dec_str[2 - i] = digit + '0';
        }
        
        // 如果整数部分需要进位
        if (carry > 0) {
            int i = 0;
            while (carry > 0 && i < integer_part.size()) {
                int digit = integer_part[i] + carry;
                if (digit >= 10) {
                    integer_part[i] = digit - 10;
                    carry = 1;
                } else {
                    integer_part[i] = digit;
                    carry = 0;
                }
                i++;
            }
            if (carry > 0) {
                integer_part.push_back(1);
            }
            
            // 重新生成整数部分的字符串
            int_str = "";
            for (int i = integer_part.size() - 1; i >= 0; i--) {
                int_str += to_string(integer_part[i]);
            }
            formatted_int = "";
            count = 0;
            for (int i = int_str.length() - 1; i >= 0; i--) {
                formatted_int = int_str[i] + formatted_int;
                count++;
                if (count % 3 == 0 && i != 0) {
                    formatted_int = "," + formatted_int;
                }
            }
        }
    }
    
    cout << formatted_int << "." << dec_str << endl;
}

// 主函数
int main() {
    string s1, op, s2;
    cin >> s1 >> op >> s2;
    
    // 去除逗号
    s1 = removeCommas(s1);
    s2 = removeCommas(s2);
    
    vector<int> num1, num2;
    bool neg1 = false, neg2 = false;
    
    if (op == "*") {
        // 处理乘法
        for (int i = s1.size() - 1; i >= 0; i--) {
            if (s1[i] == '-') {
                neg1 = true;
            } else {
                num1.push_back(s1[i] - '0');
            }
        }
        for (int i = s2.size() - 1; i >= 0; i--) {
            if (s2[i] == '-') {
                neg2 = true;
            } else {
                num2.push_back(s2[i] - '0');
            }
        }
        
        vector<int> result = multiply(num1, num2);
        
        if ((neg1 && !neg2) || (!neg1 && neg2)) {
            cout << "-";
        }
        print_mul(result);
    } else if (op == "/") {
        // 处理除法
        for (int i = s1.size() - 1; i >= 0; i--) {
            if (s1[i] == '-') {
                neg1 = true;
            } else {
                num1.push_back(s1[i] - '0');
            }
        }
        for (int i = s2.size() - 1; i >= 0; i--) {
            if (s2[i] == '-') {
                neg2 = true;
            } else {
                num2.push_back(s2[i] - '0');
            }
        }
        
        // 计算除法，保留4位小数（用于四舍五入）
        vector<int> remainder;
        
        // 将被除数乘以10000，用于保留3位小数
        for (int i = 0; i < 4; i++) {
            num1.insert(num1.begin(), 0);
        }
        
        // 计算整数商
        vector<int> quotient = divide(num1, num2, remainder);
        
        // 分离整数部分和小数部分
        // 商包含4位小数
        vector<int> integer_part, decimal_part(4, 0);
        
        if (quotient.size() <= 4) {
            // 没有整数部分
            integer_part.push_back(0);
            
            // 获取小数部分
            for (int i = 0; i < quotient.size(); i++) {
                decimal_part[3 - i] = quotient[i];
            }
        } else {
            // 获取整数部分
            for (int i = 4; i < quotient.size(); i++) {
                integer_part.push_back(quotient[i]);
            }
            
            // 获取小数部分
            for (int i = 0; i < 4; i++) {
                decimal_part[3 - i] = quotient[i];
            }
        }
        if ((neg1 && !neg2) || (!neg1 && neg2)) {
            cout << "-";
        }
        print_division_result(integer_part, decimal_part);
    }
    
    return 0;
}