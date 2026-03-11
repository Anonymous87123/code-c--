#include<bits/stdc++.h>
using namespace std;
class Product{
    public:
        static double discount;
        static double sum;
        static int n;
        Product(double d){
            discount = d;
        }
        Product(int quantity, double price){
            double realPrice = price;
            if(quantity >= 10){
                realPrice *=0.98;
            }
            realPrice *= (1 - discount);
            sum += realPrice*quantity;
            n += quantity;
        }
        static void init(){
            sum=0;n=0;
        }
        static void display(){
            double avg = 0.0;
            if(n!=0) avg = sum/n;
            cout << sum << " " << avg << endl;  // 去掉 fixed
        }
};
double Product::discount = 0.0;
double Product::sum = 0;
int Product::n = 0;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		double discount;
		cin >> discount;
		Product::discount = discount;
		Product::sum = 0;
		Product::n = 0;
		int m;
		cin >> m;
		while (m--)
		{
			int quantity;
			cin >> quantity;
			double price;
			cin >> price;
			Product(quantity, price);
		}
		Product::display();
	}
}