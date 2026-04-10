#include<bits/stdc++.h>
using namespace std;
int main(){
    int row,col;
    cin>>row>>col;
    int a[row][col],b[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>b[i][j];
        }
    }
    int e[col][row];
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cin>>e[i][j];
        }
    }
    int f[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            f[i][j]=a[i][j]+b[i][j];
        }
    }
    int c[row][row];
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            c[i][j]=0;
            for(int k=0;k<col;k++){
                c[i][j]+=a[i][k]*e[k][j];
            }
        }
    }
    cout<<"Matrix M1:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Matrix M2:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Matrix M3:"<<endl;
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout<<e[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Result of Matrix Addition:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Result of Matrix Multiplication:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}