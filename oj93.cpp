#include<bits/stdc++.h>
using namespace std;
class Date{
    public:
        int year, month, day;
        bool isLeap()const{
            return (year%4==0 && year%100!=0) || year%400==0;
        }
        int getMonthDays()const{
            int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
            if(isLeap() && month==2) return 29;
            return days[month-1];
        }
        Date(int y, int m, int d) {
            year = y;
            month = m;
            day = d;
        }
        Date operator+(int n) const{
            Date res=*this;
            while(n>0){
                res.day++;
                if(res.day>res.getMonthDays()){
                    res.day=1;
                    res.month++;
                    if(res.month>12){
                        res.month=1;
                        res.year++;
                    }
                }
                n--;
            }
            return res;
        }
        int NthDay() {
            int days=0;
            for(int i=1;i<month;i++) {
                Date temp(year,i,1);
                days+=temp.getMonthDays();
            }
            days+=day;
            return days;
        }
        friend ostream& operator<<(ostream& os, const Date& d) {
            os<<d.year<<" "<<d.month<<" "<<d.day;
            return os;
        }
};
int main() {
	int year, month, day;
	while (cin >> year >> month >> day) {
		Date d(year, month, day);
		cout << d.NthDay() << endl;
		d = d + 1039;
		cout << d << endl;
	}
	return 0;
}