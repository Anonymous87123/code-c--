/*
一、问题本质
这是一个求解二元一次不定方程 ax + by = c的问题，需要分类讨论整数解和正整数解。
二、基础数学原理
1. 裴蜀定理
对于任意整数a, b，存在整数x, y使得 ax + by = gcd(a, b)
方程 ax + by = c 有整数解当且仅当​ gcd(a, b) | c（c能被gcd(a,b)整除）
2. 扩展欧几里得算法（exgcd）
用于求解 ax + by = gcd(a, b) 的一组特解
算法递归计算 gcd 的同时，回溯计算系数 x, y
核心公式：d = exgcd(b, a mod b, y, x)和 y -= a/b * x
三、通解结构
1. 从特解到通解
假设我们找到了特解 (x₀, y₀)，即 ax₀ + by₀ = c
那么通解为：
x = x₀ + (b/d) * k
y = y₀ - (a/d) * k
其中 d = gcd(a, b)，k 是任意整数
2. 推导过程
已知：a(x₀ + (b/d)k) + b(y₀ - (a/d)k) = c
左边 = ax₀ + a(b/d)k + by₀ - b(a/d)k（凑出来很简单）
     = (ax₀ + by₀) + (ab/d - ab/d)k
     = c + 0
     = c
四、代码逻辑
1. 判断是否有解
if (c % d) {  // 不满足裴蜀定理
    cout << "-1\n";
    continue;
}
2. 计算特解
从 exgcd(a, b, x0, y0) 得到的是 ax + by = d 的特解
要得到 ax + by = c 的特解，需要乘以 c/d才可以化为ax+by=c的特解
x0 *= c / d;
y0 *= c / d;
变成ac/d x + bc/d y = c/d的特解
3. 计算通解参数
ll tx = b / d;  // x 的变化步长
ll ty = a / d;  // y 的变化步长
4. 调整到 x 的最小正整数
为了让 x 成为正整数，需要找到最小的 k 使得 x ≥ 1：
x₀ + (b/d)k ≥ 1
(b/d)k ≥ 1 - x₀
k ≥ (1 - x₀) / (b/d)
代码实现：
ll k = ceil((1.0 - x0) / tx);
x0 += tx * k;
y0 -= ty * k;
5. 分类讨论
情况1：有正整数解（y0 > 0）
此时 x0 已经是正整数，y0 也是正整数
正整数解数量：
每次 k 增加1，x 增加 tx，y 减少 ty
要保证 y 保持为正整数，最多能减少 (y0 - 1) 次
所以 k 的取值范围是 0 到 floor((y0 - 1) / ty)
解的数量 = floor((y0 - 1) / ty) + 1
最小值与最大值：
x_min = x0（k=0时）
y_min = y0 - ty * floor((y0 - 1) / ty) = (y0 - 1) % ty + 1
x_max = x0 + tx * floor((y0 - 1) / ty)
y_max = y0（k=0时）
代码对应：
ll cnt = (y0 - 1) / ty + 1;
ll x_min = x0;
ll y_min = (y0 - 1) % ty + 1;
ll x_max = x0 + (y0 - 1) / ty * tx;
ll y_max = y0;
情况2：无正整数解（y0 ≤ 0）
此时有整数解，但没有正整数解
x 的最小正整数值：
已经是 x0（因为我们调整到 x0 ≥ 1）
y 的最小正整数值：
需要调整 k 使 y 成为正整数
当前 y0 ≤ 0，要使其 ≥ 1：
y0 - ty * k ≥ 1
-ty * k ≥ 1 - y0
k ≥ (1 - y0) / ty
向上取整得到最小的 k
y_min = y0 - ty * ceil((1 - y0) / ty)
简化计算：y_min = y0 + ty * ceil((1.0 - y0) / ty)
代码对应：
ll y_min = y0 + ty * (ll)ceil((1.0 - y0) / ty);
cout << x0 << " " << y_min << "\n";
五、示例验证
以样例第一组数据为例：
a=2, b=11, c=100
d = gcd(2, 11) = 1
特解：x0=-500, y0=100（从exgcd得到）
调整后：x0=6, y0=8
tx=11, ty=2
y0=8>0，有正整数解
解的数量 = floor((8-1)/2)+1 = 4
x_min=6, y_min=(8-1)%2+1=2
x_max=6+floor(7/2)*11=39, y_max=8
六、算法复杂度
扩展欧几里得算法：O(log min(a,b))
每次查询 O(log min(a,b))
总复杂度：O(T log min(a,b))
七、关键理解点
为什么tx=b/d, ty=a/d？
因为通解中x增加b/d，y减少a/d才能保持等式平衡
为什么用ceil函数？
我们需要k是整数，且满足不等式，所以需要向上取整
为什么y_min计算是(y0-1)%ty+1？
这确保了y最小为1
例如：y0=8, ty=2 → (8-1)%2+1=2
为什么分开计算x和y的最小正值？
当没有正整数解时，x和y的最小正值可能不在同一组解中
题目要求分别输出整数解中x和y的最小正整数值
这个算法充分利用了线性丢番图方程的通解结构，通过数学分析减少了需要枚举的情况，从而在O(1)时间内完成大部分计算，只在必要时进行简单的算术操作。
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        ll a, b, c;
        cin >> a >> b >> c;
        
        ll x0, y0;
        ll d = exgcd(a, b, x0, y0);
        // 无整数解
        if (c % d) {
            cout << "-1\n";
            continue;
        }
        // 调整特解
        x0 *= c / d;
        y0 *= c / d;
        ll tx = b / d, ty = a / d;
        // 计算 k 使得 x 为正整数
        ll k = ceil((1.0 - x0) / tx);
        x0 += tx * k;
        y0 -= ty * k;
        if (y0 <= 0) {//无正整数解
            //计算y的最小正整数解
            ll y_min = y0 + ty * (ll)ceil((1.0 - y0) / ty);
            cout << x0 << " " << y_min << "\n";
        } else {//有正整数解
            ll cnt = (y0 - 1) / ty + 1;// 正整数解数量
            ll x_min = x0; // x 的最小值
            ll y_min = (y0 - 1) % ty + 1;// y 的最小值
            ll x_max = x0 + (y0 - 1) / ty * tx;// x 的最大值
            ll y_max = y0;// y 的最大值
            cout << cnt << " "
                 << x_min << " "
                 << y_min << " "
                 << x_max << " "
                 << y_max << "\n";
        }
    }
    return 0;
}
