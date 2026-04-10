#include<bits/stdc++.h>
using namespace std;
class point{
    public:
        double x,y;
        point(double a,double b){x=a;y=b;}
};
class triangle{
    public:
        point a,b,c,m;
        double cross(const point& p1,const point& p2,const point& p3){
            return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
        }
        triangle(point p1,point p2,point p3,point m):a(p1),b(p2),c(p3),m(m){}
        bool judge(){
            double d1=cross(a,b,m);
            double d2=cross(b,c,m);
            double d3=cross(c,a,m);
            return (d1>0&&d2>0&&d3>0)||(d1<0&&d2<0&&d3<0);
        }
};
int main() {
	double x1, y1, x2, y2, x3, y3;
	double x, y;
	while (cin >> x1 >> y1) {
		cin >> x2 >> y2;
		cin >> x3 >> y3;
		cin >> x >> y;
		point a(x1, y1);
		point b(x2, y2);
		point c(x3, y3);
		point m(x, y);
		triangle t(a, b, c, m);
		if (t.judge()) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}