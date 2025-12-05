#include<bits/stdc++.h>
using namespace std;
struct Employee {
    int id;
    int age;
    char gender;
    Employee* next;
};
Employee* insert(Employee* tail, int id, int age, char gender) {
    Employee* newEmployee = new Employee;
    newEmployee->id = id;
    newEmployee->age = age;
    newEmployee->gender = gender;
    newEmployee->next = nullptr;
    if (tail != nullptr) {
        tail->next = newEmployee;
    }
    return newEmployee;
}
void output(Employee* head) {
    Employee* current = head;
    while (current != nullptr) {
        cout << current->id << " " << current->age << " " << current->gender << endl;
        current = current->next;
    }
}
void countGender(Employee* head) {
    int male = 0, female = 0;
    Employee* current = head;
    while (current != nullptr) {
        if (current->gender == 'M') {
            male++;
        } else {
            female++;
        }
        current = current->next;
    }
    
    cout << male << " " << female << endl;
}
Employee* deleteById(Employee* head, int id, Employee* &tail) {
    Employee* current = head;
    Employee* prev = nullptr;
    
    while (current != nullptr) {
        if (current->id == id) {
            if (prev == nullptr) {
                head = current->next;
                if (tail == current) {
                    tail = nullptr; 
                }
            } else {
                prev->next = current->next;
                if (tail == current) {
                    tail = prev; 
                }
            }
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }
    return head;
}
Employee* retire(Employee* head, Employee* &tail) {
    Employee* retiredHead = nullptr;
    Employee* retiredTail = nullptr;
    Employee* current = head;
    Employee* prev = nullptr;
    while (current != nullptr) {
        bool shouldRetire = false;
        if ((current->gender == 'M' && current->age > 60) || 
            (current->gender == 'F' && current->age > 55)) {
            shouldRetire = true;
        }
        if (shouldRetire) {
            if (retiredHead == nullptr) {
                retiredHead = current;
                retiredTail = current;
            } else {
                retiredTail->next = current;
                retiredTail = current;
            }
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            if (tail == current) {
                tail = prev;
            }
            current = current->next;
            retiredTail->next = nullptr;
        } else {
            prev = current;
            current = current->next;
        }
    }
    output(retiredHead);
    current = retiredHead;
    while (current != nullptr) {
        Employee* temp = current;
        current = current->next;
        delete temp;
    }
    return head;
}
void freeList(Employee* head) {
    Employee* current = head;
    while (current != nullptr) {
        Employee* temp = current;
        current = current->next;
        delete temp;
    }
}
int main() {
    int n;
    while (cin >> n) {
        Employee* head = nullptr;
        Employee* tail = nullptr;
        for (int i = 0; i < n; i++) {
            int id, age;
            string genderStr;
            cin >> id >> age >> genderStr;
            char gender = genderStr[0];
            if (head == nullptr) {
                head = new Employee;
                head->id = id;
                head->age = age;
                head->gender = gender;
                head->next = nullptr;
                tail = head;
            } else {
                tail = insert(tail, id, age, gender);
            }
        }
        string command;
        while (cin >> command) {
            if (command == "end") {
                break;
            } else if (command == "output") {
                output(head);
            } else if (command == "count_gender") {
                countGender(head);
            } else if (command == "insert") {
                int id, age;
                string genderStr;
                cin >> id >> age >> genderStr;
                char gender = genderStr[0];
                if (head == nullptr) {
                    head = new Employee;
                    head->id = id;
                    head->age = age;
                    head->gender = gender;
                    head->next = nullptr;
                    tail = head;
                } else {
                    tail = insert(tail, id, age, gender);
                }
            } else if (command == "delete") {
                int id;
                cin >> id;
                head = deleteById(head, id, tail);
            } else if (command == "retire") {
                head = retire(head, tail);
            }
        }
        freeList(head);
    }
    return 0;
}
    