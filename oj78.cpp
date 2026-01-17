#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

// 计算两个数的运算
int calculate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;  // 整数除法
        default: return 0;
    }
}

// 获取运算符优先级
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;  // 括号或其他字符
}

// 执行计算
int evaluateExpression(const string& expr) {
    stack<int> numbers;   // 操作数栈
    stack<char> ops;      // 运算符栈
    
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        
        // 跳过空格
        if (c == ' ') continue;
        
        // 如果是数字，读取整个数字
        if (isdigit(c)) {
            int num = 0;
            while (i < expr.length() && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;  // 回退一个字符
            numbers.push(num);
        }
        // 如果是左括号
        else if (c == '(') {
            ops.push(c);
        }
        // 如果是右括号
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int b = numbers.top(); numbers.pop();
                int a = numbers.top(); numbers.pop();
                char op = ops.top(); ops.pop();
                numbers.push(calculate(a, b, op));
            }
            ops.pop();  // 弹出左括号
        }
        // 如果是运算符
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // 处理负数：如果当前字符是减号，且前一个字符是'('或字符串开头
            if (c == '-' && (i == 0 || expr[i-1] == '(')) {
                // 读取负数
                i++;
                int num = 0;
                bool isNegative = true;
                while (i < expr.length() && isdigit(expr[i])) {
                    num = num * 10 + (expr[i] - '0');
                    i++;
                }
                i--;
                numbers.push(-num);
                continue;
            }
            
            // 当栈顶运算符优先级不低于当前运算符时，先计算
            while (!ops.empty() && getPriority(ops.top()) >= getPriority(c)) {
                int b = numbers.top(); numbers.pop();
                int a = numbers.top(); numbers.pop();
                char op = ops.top(); ops.pop();
                numbers.push(calculate(a, b, op));
            }
            ops.push(c);
        }
    }
    
    // 处理剩余运算符
    while (!ops.empty()) {
        int b = numbers.top(); numbers.pop();
        int a = numbers.top(); numbers.pop();
        char op = ops.top(); ops.pop();
        numbers.push(calculate(a, b, op));
    }
    
    return numbers.top();
}

int main() {
    string expression;
    
    cout << "请输入四则运算表达式（支持+ - * / ( )，整数运算）：" << endl;
    cout << "例如：2+3*(4-1)/2" << endl;
    cout << "输入表达式: ";
    while(getline(cin, expression))
    {
    // 去除表达式中可能的空格
    string cleanedExpr = "";
    for (char c : expression) {
        if (c != ' ') cleanedExpr += c;
    }
    
    try {
        int result = evaluateExpression(cleanedExpr);
        cout << "计算结果: " << result << endl;
    } catch (exception& e) {
        cout << "计算过程中发生错误：" << e.what() << endl;
    }}
    
    return 0;
}