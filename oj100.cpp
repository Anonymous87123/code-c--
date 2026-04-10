#include <iostream>
using namespace std;
class Vehicle {
public:
    virtual void display() = 0;
    // 虚析构函数，防止派生类析构不完整
    virtual ~Vehicle() {}
};
class Car : public Vehicle {
private:
    int passenger_num; // 载客数
    int weight;        // 重量
public:
    Car(int num, int kg) : passenger_num(num), weight(kg) {}
    
    // 重写 display 方法，计算并输出费用
    void display() override {
        double fee = passenger_num * 8 + weight * 2;
        cout << fee << endl;
    }
};

// 卡车类 Truck，继承自 Vehicle
class Truck : public Vehicle {
private:
    int weight; // 重量
public:
    // 构造函数
    Truck(int kg) : weight(kg) {}
    
    // 重写 display 方法
    void display() override {
        double fee = weight * 5;
        cout << fee << endl;
    }
};

// 公交车类 Bus，继承自 Vehicle
class Bus : public Vehicle {
private:
    int passenger_num; // 载客数
public:
    // 构造函数
    Bus(int num) : passenger_num(num) {}
    
    // 重写 display 方法
    void display() override {
        double fee = passenger_num * 3;
        cout << fee << endl;
    }
};

// 题目给定的 main 函数，无需修改
int main() {
    Vehicle* pd[10];
    int t, num, i = 0;
    double kg;
    cin >> t;
    while (t > 0) {
        if (t == 1) {
            cin >> num >> kg;
            pd[i] = new Car(num, kg);
        }
        else if (t == 2) {
            cin >> kg;
            pd[i] = new Truck(kg);
        }
        else if (t == 3) {
            cin >> num;
            pd[i] = new Bus(num);
        }
        pd[i]->display();
        i++;
        cin >> t;
    }
    return 0;
}