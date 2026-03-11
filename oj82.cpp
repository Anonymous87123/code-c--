#include<bits/stdc++.h>
using namespace std;
class Student{
    private:
        double score;
        static double total;
        static int count;
    public:
        void scoreTotalCount(double s){
            score=s;total+=s;count++;
        }
        static double sum(){
            return total;
        }
        static double average(){
            if(count==0) return 0;
            return total/count;
        }
};
double Student::total = 0.0;
int Student::count = 0;
int main() {
	vector<Student> students; // 存储学生对象的向量
	double score;
	int numStudents;
	// 输入学生人数
	cout << "请输入学生人数：";
	cin >> numStudents;
	// 输入每个学生的成绩
	for (int i = 0; i < numStudents; ++i) {
		cout << "请输入第 " << (i + 1) << " 个学生的成绩：";
		cin >> score;
		students.push_back(Student());
		students[i].scoreTotalCount(score);
	}
	// 输出总分和平均分
	cout << "全班学生的总分是：" << Student::sum() << endl; cout << "全班学生的平均分是：" << fixed << setprecision(2) << Student::average() << endl;
	return 0;
}