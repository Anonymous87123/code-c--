#include <bits/stdc++.h>
using namespace std;
string toupperCase(string s) {
    for (int i = 0; i < s.size(); ++i) {
        s[i] = toupper(s[i]);
    }
    return s;
}
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void info() = 0;
    virtual ~Person() {}
};

class Male : public Person {
private:
    // 静态计数器，统计Male实例总数
    static int MaleCnt;
public:
    Male(string n, int a) : Person(n, a) {
        MaleCnt++;
    }
    void info() override {
        cout << "Male " << name << " " << age << endl;
    }
    static void stat() {
        cout << MaleCnt << endl;
    }
};


class Female : public Person {
private:

    static int FemaleCnt;
public:
    Female(string n, int a) : Person(n, a) {
        FemaleCnt++;
    }
    
    void info() override {
        cout << "Female " << name << " " << age << endl;
    }
    static void stat() {
        cout << FemaleCnt << endl;
    }
};

int Male::MaleCnt = 0;
int Female::FemaleCnt = 0;

// 题目给定的main函数，无需修改
int main() {
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string gender;
        string name;
        int age;
        Person* person = NULL;
        iss >> gender >> name >> age;
        if (gender == "M") {
            person = new Male(toupperCase(name), age);
        }
        else if (gender == "F") {
            person = new Female(toupperCase(name), age);
        }
        if (person) {
            person->info();
            delete person; // 释放动态分配的内存
        }
    }
    Male::stat();
    Female::stat();
    return 0;
}