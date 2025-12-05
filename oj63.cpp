#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    int a[10][9];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>a[i][j];
        }
    }
    int count1 = 0;
    for(int i=x-1; i>=0 && count1<=2; i--)
    {
        if(a[i][y]==0&&count1==0){a[i][y]=3;}
        else if(a[i][y]!=0)
        {
            count1++;
            if(count1==1)continue;
            else if(a[i][y]==2&&count1==2){
                a[i][y]=3;
            }
        }
    }
    int count2 = 0;
    for(int i=x+1; i<10 && count2<=2; i++)
    {
        if(a[i][y]==0&&count2==0){a[i][y]=3;}
        else if(a[i][y]!=0)
        {
            count2++;
            if(count2==1)continue;
            else if(a[i][y]==2&&count2==2){
                a[i][y]=3;
            }
        }
    }
    int count3 = 0;
    for(int j=y-1; j>=0 && count3<=2; j--)
    {
        if(a[x][j]==0&&count3==0){a[x][j]=3;}
        else if(a[x][j]!=0)
        {
            count3++;
            if(count3==1)continue;
            else if(a[x][j]==2&&count3==2){
                a[x][j]=3;
            }
        }
    }
    int count4 = 0;
    for(int j=y+1; j<9 && count4<=2; j++)
    {
        if(a[x][j]==0&&count4==0){a[x][j]=3;}
        else if(a[x][j]!=0)
        {
            count4++;
            if(count4==1)continue;
            else if(a[x][j]==2&&count4==2){
                a[x][j]=3;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}