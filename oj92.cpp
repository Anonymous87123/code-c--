#include<bits/stdc++.h>
using namespace std;
class Array{
    public:
        vector<vector<int>> data;
        int rows,cols;
        Array():rows(0),cols(0){};
        void inputarr1(int r,int c){
            rows=r;
            cols=c;
            data.resize(rows,vector<int>(cols));
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    cin>>data[i][j];
                }
            }
        }
        void inputarr2(int r,int c){
            rows=r;
            cols=c;
            data.resize(rows,vector<int>(cols));
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    cin>>data[i][j];
            }}
        }
        friend Array operator+(const Array& a,const Array& b){
            Array res;
            res.rows=a.rows;
            res.cols=a.cols;
            res.data.resize(res.rows,vector<int>(res.cols));
            for(int i=0;i<res.rows;i++){
                for(int j=0;j<res.cols;j++){
                    res.data[i][j]=a.data[i][j]+b.data[i][j];
                }
            }
            return res;
        }
        Array operator-(const Array& other)const{
            Array res;
            res.rows=rows;
            res.cols=cols;
            res.data.resize(res.rows,vector<int>(res.cols));
            for(int i=0;i<res.rows;i++){
                for(int j=0;j<res.cols;j++){
                    res.data[i][j]=data[i][j]-other.data[i][j];
                }
            }
            return res;
        }
        void show()const{
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    cout<<data[i][j]<<" ";
                }
            }
        }
};
int main(){
    Array rr,aa,p3;
    int a,b,c,d;
    while(cin>>a>>b>>c>>d){
        rr.inputarr1(a,b);
        aa.inputarr1(c,d);
        p3=rr+aa;
        cout << "Addition result:";
        p3.show();
        cout<<" ";
        p3=rr-aa;
        cout << "Subtraction result:";
        p3.show();
        cout<<endl;
    }
    return 0;
}