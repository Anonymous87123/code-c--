#include<bits/stdc++.h>
using namespace std;
void print(double a,double b){
    if(b==0.00){
        cout<<fixed<<setprecision(2)<<a<<endl;
    }
    else{
        if(a>=0&&b>0){
            cout<<fixed<<setprecision(2)<<a<<"+"<<fixed<<setprecision(2)<<b<<"*i"<<endl;
        }else if(a>0&&b<0){
            cout<<fixed<<setprecision(2)<<a<<fixed<<setprecision(2)<<b<<"*i"<<endl;
        }else if(a<0&&b>0){
            cout<<fixed<<setprecision(2)<<a<<"+"<<fixed<<setprecision(2)<<b<<"*i"<<endl;
        }else if(a<0&&b<0){
            cout<<fixed<<setprecision(2)<<a<<fixed<<setprecision(2)<<b<<"*i"<<endl;
        }
    }
}
int main(){
    double a_real,a_image,b_real,b_image;
    while(cin>>a_real>>a_image>>b_real>>b_image){
        double plus_real=a_real+b_real;
        double plus_image=a_image+b_image;
        print(plus_real,plus_image);
        double minus_real=a_real-b_real;
        double minus_image=a_image-b_image;
        print(minus_real,minus_image);
        double multiply_real=a_real*b_real-a_image*b_image;
        double multiply_image=a_real*b_image+a_image*b_real;
        print(multiply_real,multiply_image);
        double denominator = b_real*b_real + b_image*b_image;
        double divide_real = (a_real*b_real + a_image*b_image) / denominator;
        double divide_image = (a_image*b_real - a_real*b_image) / denominator;
        print(divide_real,divide_image);
    }
    return 0;
}