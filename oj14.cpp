#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int result[n]={0};
    for(int i=0;i<n;i++)
    {
        int week[7];
        for(int j=0;j<=6;j++)
        {
            cin>>week[j];
        }
        for (int k=0;k<=6;k++)
        {
            for (int k1=k+1;k1<7;k1++)
            {
                int temp=week[k1]-week[k];
                if(temp>result[i])result[i]=temp;
            }
        }
    }
    for(int m=0;m<n;m++)cout<<result[m]<<endl;
}