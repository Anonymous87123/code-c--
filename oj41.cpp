#include<iostream>
using namespace std;
void findMax(double a, double b, double c, double *maxPtr) {
    *maxPtr = a;
    if (b > *maxPtr) *maxPtr = b;
    if (c > *maxPtr) *maxPtr = c;
}
void findMin(double a, double b, double c, double *minPtr) {
    *minPtr = a;
    if (b < *minPtr) *minPtr = b;
    if (c < *minPtr) *minPtr = c;
}
void fmaxmin(double a, double b, double c, double *maxPtr, double *minPtr) {
    findMax(a, b, c, maxPtr);
    findMin(a, b, c, minPtr);
}
int main() {
    double a, b, c, max, min;
    cout << "a,b,c = ";
    cin >> a >> b >> c;
    fmaxmin(a, b, c, &max, &min);
    cout << "max=" << max << endl;
    cout << "min=" << min << endl;
    return 0;
}